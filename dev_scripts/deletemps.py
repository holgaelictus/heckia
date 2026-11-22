#!/usr/bin/env python3
import argparse
import json
import re
import shutil
import sys
from pathlib import Path

# Ajusta aqui los prefijos o nombres exactos de carpetas en data/maps/ a conservar
KEEP_PREFIXES = ("A0_",)
KEEP_EXACT = set()

ROOT = Path(".")
MAPS_DIR = ROOT / "data/maps"
LAYOUTS_DIR = ROOT / "data/layouts"
MAP_GROUPS_JSON = MAPS_DIR / "map_groups.json"
LAYOUTS_JSON = LAYOUTS_DIR / "layouts.json"
EVENT_SCRIPTS_S = ROOT / "data/event_scripts.s"
WILD_ENCOUNTERS_JSON = ROOT / "src/data/wild_encounters.json"
HEAL_LOCATIONS_JSON = ROOT / "src/data/heal_locations.json"

INCLUDE_RE = re.compile(r'^\s*\.include\s+"data/maps/([^/]+)/scripts\.inc"')


def should_keep_map(name: str) -> bool:
    return name in KEEP_EXACT or name.startswith(KEEP_PREFIXES)


def main() -> None:
    parser = argparse.ArgumentParser(description="Purga mapas vanilla de Hoenn conservando mapas propios.")
    parser.add_argument("--apply", action="store_true", help="Aplica los cambios y borra los archivos.")
    args = parser.parse_args()

    mg_data = json.loads(MAP_GROUPS_JSON.read_text(encoding="utf-8"))
    new_group_order = []
    kept_map_names = set()
    removed_map_names = set()

    for group_name in mg_data["group_order"]:
        maps = mg_data.get(group_name, [])
        kept = [m for m in maps if should_keep_map(m)]
        removed = [m for m in maps if not should_keep_map(m)]
        kept_map_names.update(kept)
        removed_map_names.update(removed)
        if kept:
            new_group_order.append(group_name)
            mg_data[group_name] = kept
        else:
            mg_data.pop(group_name, None)

    if not kept_map_names:
        sys.exit("ERROR: No se encontro ningun mapa que cumpla KEEP_PREFIXES / KEEP_EXACT. Abortando.")

    mg_data["group_order"] = new_group_order

    # Leer map.json de los mapas conservados para saber sus IDs y layouts
    kept_map_ids = set()
    kept_layout_ids = set()
    dangling_refs = []

    for map_name in sorted(kept_map_names):
        mjson_path = MAPS_DIR / map_name / "map.json"
        if not mjson_path.exists():
            sys.exit(f"ERROR: Falta {mjson_path}")
        mdata = json.loads(mjson_path.read_text(encoding="utf-8"))
        kept_map_ids.add(mdata["id"])
        kept_layout_ids.add(mdata["layout"])

    # Comprobar warps y conexiones huerfanas en mapas conservados
    for map_name in sorted(kept_map_names):
        mdata = json.loads((MAPS_DIR / map_name / "map.json").read_text(encoding="utf-8"))
        for w in mdata.get("warp_events", []):
            dest = w.get("dest_map")
            if dest and dest not in kept_map_ids and dest != "MAP_DYNAMIC":
                dangling_refs.append(f"{map_name}: warp -> {dest}")
        for c in mdata.get("connections", []) or []:
            dest = c.get("map")
            if dest and dest not in kept_map_ids:
                dangling_refs.append(f"{map_name}: connection -> {dest}")

    # Filtrar layouts.json y detectar carpetas de layouts a conservar
    layouts_data = json.loads(LAYOUTS_JSON.read_text(encoding="utf-8"))
    kept_layouts = []
    kept_layout_dirs = set()
    for entry in layouts_data["layouts"]:
        if isinstance(entry, dict) and entry.get("id") in kept_layout_ids:
            kept_layouts.append(entry)
            for key in ("blockdata_filepath", "border_filepath"):
                if key in entry:
                    kept_layout_dirs.add(Path(entry[key]).parent.name)
    layouts_data["layouts"] = kept_layouts

    # Carpetas a eliminar
    map_dirs_to_del = [p for p in MAPS_DIR.iterdir() if p.is_dir() and p.name not in kept_map_names]
    layout_dirs_to_del = [p for p in LAYOUTS_DIR.iterdir() if p.is_dir() and p.name not in kept_layout_dirs]

    # Filtrar data/event_scripts.s
    es_lines = EVENT_SCRIPTS_S.read_text(encoding="utf-8").splitlines(keepends=True)
    new_es_lines = []
    removed_includes = 0
    for line in es_lines:
        m = INCLUDE_RE.match(line)
        if m and m.group(1) not in kept_map_names:
            removed_includes += 1
            continue
        new_es_lines.append(line)

    # Resumen
    print(f"Modo: {'APLICANDO CAMBIOS' if args.apply else 'DRY-RUN (usa --apply para ejecutar)'}")
    print(f"Mapas conservados ({len(kept_map_names)}): {', '.join(sorted(kept_map_names))}")
    print(f"Layouts conservados ({len(kept_layout_ids)}): {', '.join(sorted(kept_layout_ids))}")
    print(f"Carpetas de mapas a borrar: {len(map_dirs_to_del)}")
    print(f"Carpetas de layouts a borrar: {len(layout_dirs_to_del)}")
    print(f"Lineas .include a quitar en event_scripts.s: {removed_includes}")

    if dangling_refs:
        print("\nAVISO - Referencias en tus mapas hacia mapas que se van a borrar:")
        for ref in dangling_refs:
            print(f"  - {ref}")

    if not args.apply:
        return

    # Escribir JSON y borrar carpetas
    MAP_GROUPS_JSON.write_text(json.dumps(mg_data, indent=2) + "\n", encoding="utf-8")
    LAYOUTS_JSON.write_text(json.dumps(layouts_data, indent=2) + "\n", encoding="utf-8")
    EVENT_SCRIPTS_S.write_text("".join(new_es_lines), encoding="utf-8")

    for d in map_dirs_to_del:
        shutil.rmtree(d)
    for d in layout_dirs_to_del:
        shutil.rmtree(d)

    # Limpiar wild_encounters.json si existe
    if WILD_ENCOUNTERS_JSON.exists():
        we_data = json.loads(WILD_ENCOUNTERS_JSON.read_text(encoding="utf-8"))
        for grp in we_data.get("wild_encounter_groups", []):
            if "encounters" in grp:
                grp["encounters"] = [e for e in grp["encounters"] if e.get("map") in kept_map_ids]
        WILD_ENCOUNTERS_JSON.write_text(json.dumps(we_data, indent=2) + "\n", encoding="utf-8")

    # Limpiar heal_locations.json si existe
    if HEAL_LOCATIONS_JSON.exists():
        hl_data = json.loads(HEAL_LOCATIONS_JSON.read_text(encoding="utf-8"))
        if "heal_locations" in hl_data:
            kept_hl = [h for h in hl_data["heal_locations"] if h.get("map") in kept_map_ids]
            if kept_hl:
                hl_data["heal_locations"] = kept_hl
                HEAL_LOCATIONS_JSON.write_text(json.dumps(hl_data, indent=2) + "\n", encoding="utf-8")
            else:
                print("AVISO: heal_locations.json no se modifico porque quedaria vacio.")

    print("\nLimpieza de mapas completada.")


if __name__ == "__main__":
    main()