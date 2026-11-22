A0_Inicio_2_MapScripts::
# 9 "data/maps/A0_Inicio_2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, A0_Inicio_2_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

A0_Inicio_2_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 10 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 7
	goto_if_eq A0_Inicio_2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

A0_Inicio_2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 11 "data/maps/A0_Inicio_2/scripts.pory"
	call A0_Inicio_2_Script_AplicarPuzzleResuelto
	return


A0_Inicio_2_EventScript_NpcKitPruebas::
# 17 "data/maps/A0_Inicio_2/scripts.pory"
	lock
# 18 "data/maps/A0_Inicio_2/scripts.pory"
	faceplayer
# 20 "data/maps/A0_Inicio_2/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, A0_Inicio_2_EventScript_NpcKitPruebas_2
# 30 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox Text_KitBienvenida, MSGBOX_YESNO
# 31 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq A0_Inicio_2_EventScript_NpcKitPruebas_5
# 37 "data/maps/A0_Inicio_2/scripts.pory"
	message A0_Inicio_2_EventScript_NpcKitPruebas_Text_2
# 38 "data/maps/A0_Inicio_2/scripts.pory"
	waitmessage
# 39 "data/maps/A0_Inicio_2/scripts.pory"
	dynmultichoice 15, 2, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, A0_Inicio_2_EventScript_NpcKitPruebas_Text_3, A0_Inicio_2_EventScript_NpcKitPruebas_Text_4, A0_Inicio_2_EventScript_NpcKitPruebas_Text_5
# 44 "data/maps/A0_Inicio_2/scripts.pory"
	closemessage
# 46 "data/maps/A0_Inicio_2/scripts.pory"
	switch VAR_RESULT
# 47 "data/maps/A0_Inicio_2/scripts.pory"
	case 0, A0_Inicio_2_EventScript_NpcKitPruebas_12
# 49 "data/maps/A0_Inicio_2/scripts.pory"
	case 1, A0_Inicio_2_EventScript_NpcKitPruebas_13
# 52 "data/maps/A0_Inicio_2/scripts.pory"
	givemon SPECIES_TORCHIC, 15, ITEM_ORAN_BERRY
A0_Inicio_2_EventScript_NpcKitPruebas_10:
# 55 "data/maps/A0_Inicio_2/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 56 "data/maps/A0_Inicio_2/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 57 "data/maps/A0_Inicio_2/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 59 "data/maps/A0_Inicio_2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 60 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_NpcKitPruebas_Text_6, MSGBOX_DEFAULT
# 61 "data/maps/A0_Inicio_2/scripts.pory"
	waitfanfare
# 63 "data/maps/A0_Inicio_2/scripts.pory"
	giveitem ITEM_POKE_BALL, 10
# 64 "data/maps/A0_Inicio_2/scripts.pory"
	giveitem ITEM_SUPER_POTION, 5
# 65 "data/maps/A0_Inicio_2/scripts.pory"
	giveitem ITEM_RARE_CANDY, 5
# 67 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_NpcKitPruebas_2:
# 21 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox Text_KitYaActivo, MSGBOX_YESNO
# 22 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq A0_Inicio_2_EventScript_NpcKitPruebas_8
A0_Inicio_2_EventScript_NpcKitPruebas_7:
# 26 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_NpcKitPruebas_5:
# 32 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_NpcKitPruebas_Text_1, MSGBOX_DEFAULT
# 33 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_NpcKitPruebas_8:
# 23 "data/maps/A0_Inicio_2/scripts.pory"
	call A0_Inicio_2_Script_CurarEquipoConEfecto
# 24 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_NpcKitPruebas_Text_0, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_NpcKitPruebas_7

A0_Inicio_2_EventScript_NpcKitPruebas_12:
# 48 "data/maps/A0_Inicio_2/scripts.pory"
	givemon SPECIES_MUDKIP, 15, ITEM_ORAN_BERRY
	goto A0_Inicio_2_EventScript_NpcKitPruebas_10

A0_Inicio_2_EventScript_NpcKitPruebas_13:
# 50 "data/maps/A0_Inicio_2/scripts.pory"
	givemon SPECIES_TREECKO, 15, ITEM_ORAN_BERRY
	goto A0_Inicio_2_EventScript_NpcKitPruebas_10


A0_Inicio_2_EventScript_NpcContador::
# 72 "data/maps/A0_Inicio_2/scripts.pory"
	lock
# 73 "data/maps/A0_Inicio_2/scripts.pory"
	faceplayer
# 75 "data/maps/A0_Inicio_2/scripts.pory"
	addvar VAR_TEMP_2, 1
# 76 "data/maps/A0_Inicio_2/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_2
# 78 "data/maps/A0_Inicio_2/scripts.pory"
	switch VAR_TEMP_2
# 79 "data/maps/A0_Inicio_2/scripts.pory"
	case 1, A0_Inicio_2_EventScript_NpcContador_3
# 81 "data/maps/A0_Inicio_2/scripts.pory"
	case 3, A0_Inicio_2_EventScript_NpcContador_4
# 83 "data/maps/A0_Inicio_2/scripts.pory"
	case 5, A0_Inicio_2_EventScript_NpcContador_5
# 86 "data/maps/A0_Inicio_2/scripts.pory"
	case 10, A0_Inicio_2_EventScript_NpcContador_6
# 90 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_NpcContador_Text_4, MSGBOX_DEFAULT
A0_Inicio_2_EventScript_NpcContador_1:
# 93 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_NpcContador_3:
# 80 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_NpcContador_Text_0, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_NpcContador_1

A0_Inicio_2_EventScript_NpcContador_4:
# 82 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_NpcContador_Text_1, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_NpcContador_1

A0_Inicio_2_EventScript_NpcContador_5:
# 84 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_NpcContador_Text_2, MSGBOX_DEFAULT
# 85 "data/maps/A0_Inicio_2/scripts.pory"
	giveitem ITEM_SUPER_POTION, 1
	goto A0_Inicio_2_EventScript_NpcContador_1

A0_Inicio_2_EventScript_NpcContador_6:
# 87 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_NpcContador_Text_3, MSGBOX_DEFAULT
# 88 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_2, 0
	goto A0_Inicio_2_EventScript_NpcContador_1


A0_Inicio_2_EventScript_CartelMenu::
# 98 "data/maps/A0_Inicio_2/scripts.pory"
	lockall
# 99 "data/maps/A0_Inicio_2/scripts.pory"
	message A0_Inicio_2_EventScript_CartelMenu_Text_0
# 100 "data/maps/A0_Inicio_2/scripts.pory"
	waitmessage
# 102 "data/maps/A0_Inicio_2/scripts.pory"
	dynmultichoice 13, 1, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, A0_Inicio_2_EventScript_CartelMenu_Text_1, A0_Inicio_2_EventScript_CartelMenu_Text_2, A0_Inicio_2_EventScript_CartelMenu_Text_3, A0_Inicio_2_EventScript_CartelMenu_Text_4, A0_Inicio_2_EventScript_CartelMenu_Text_5
# 109 "data/maps/A0_Inicio_2/scripts.pory"
	closemessage
# 111 "data/maps/A0_Inicio_2/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/A0_Inicio_2/scripts.pory"
	case 0, A0_Inicio_2_EventScript_CartelMenu_3
# 115 "data/maps/A0_Inicio_2/scripts.pory"
	case 1, A0_Inicio_2_EventScript_CartelMenu_4
# 120 "data/maps/A0_Inicio_2/scripts.pory"
	case 2, A0_Inicio_2_EventScript_CartelMenu_5
# 125 "data/maps/A0_Inicio_2/scripts.pory"
	case 3, A0_Inicio_2_EventScript_CartelMenu_6
# 130 "data/maps/A0_Inicio_2/scripts.pory"
	case 4, A0_Inicio_2_EventScript_CartelMenu_7
A0_Inicio_2_EventScript_CartelMenu_1:
# 140 "data/maps/A0_Inicio_2/scripts.pory"
	releaseall
	end

A0_Inicio_2_EventScript_CartelMenu_3:
# 113 "data/maps/A0_Inicio_2/scripts.pory"
	call A0_Inicio_2_Script_CurarEquipoConEfecto
# 114 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CartelMenu_Text_6, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_CartelMenu_1

A0_Inicio_2_EventScript_CartelMenu_4:
# 116 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_6, WEATHER_RAIN
# 117 "data/maps/A0_Inicio_2/scripts.pory"
	setweather WEATHER_RAIN
# 118 "data/maps/A0_Inicio_2/scripts.pory"
	doweather
# 119 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CartelMenu_Text_7, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_CartelMenu_1

A0_Inicio_2_EventScript_CartelMenu_5:
# 121 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_6, WEATHER_SANDSTORM
# 122 "data/maps/A0_Inicio_2/scripts.pory"
	setweather WEATHER_SANDSTORM
# 123 "data/maps/A0_Inicio_2/scripts.pory"
	doweather
# 124 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CartelMenu_Text_8, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_CartelMenu_1

A0_Inicio_2_EventScript_CartelMenu_6:
# 126 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_6, WEATHER_NONE
# 127 "data/maps/A0_Inicio_2/scripts.pory"
	setweather WEATHER_NONE
# 128 "data/maps/A0_Inicio_2/scripts.pory"
	doweather
# 129 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CartelMenu_Text_9, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_CartelMenu_1

A0_Inicio_2_EventScript_CartelMenu_7:
# 131 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_1, 0
# 132 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_2, 0
# 133 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_3, 0
# 134 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_4, 0
# 135 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_5, 0
# 136 "data/maps/A0_Inicio_2/scripts.pory"
	playse SE_PC_OFF
# 137 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CartelMenu_Text_10, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_CartelMenu_1


A0_Inicio_2_EventScript_TriggerAviso::
# 145 "data/maps/A0_Inicio_2/scripts.pory"
	lockall
# 146 "data/maps/A0_Inicio_2/scripts.pory"
	playse SE_PIN
# 147 "data/maps/A0_Inicio_2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, A0_Inicio_2_EventScript_TriggerAviso_Movement_0
# 148 "data/maps/A0_Inicio_2/scripts.pory"
	waitmovement 0
# 150 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_TriggerAviso_Text_0, MSGBOX_DEFAULT
# 152 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_1, 1
# 153 "data/maps/A0_Inicio_2/scripts.pory"
	releaseall
	end


A0_Inicio_2_EventScript_InterruptorA::
# 158 "data/maps/A0_Inicio_2/scripts.pory"
	lock
# 159 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 1
	goto_if_eq A0_Inicio_2_EventScript_InterruptorA_2
# 159 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 3
	goto_if_eq A0_Inicio_2_EventScript_InterruptorA_2
# 159 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 5
	goto_if_eq A0_Inicio_2_EventScript_InterruptorA_2
# 159 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 7
	goto_if_eq A0_Inicio_2_EventScript_InterruptorA_2
# 162 "data/maps/A0_Inicio_2/scripts.pory"
	addvar VAR_TEMP_3, 1
# 163 "data/maps/A0_Inicio_2/scripts.pory"
	playse SE_SWITCH
# 164 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_InterruptorA_Text_1, MSGBOX_DEFAULT
# 165 "data/maps/A0_Inicio_2/scripts.pory"
	call A0_Inicio_2_Script_VerificarBitmask
A0_Inicio_2_EventScript_InterruptorA_1:
# 167 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_InterruptorA_2:
# 160 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_InterruptorA_Text_0, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_InterruptorA_1


A0_Inicio_2_EventScript_InterruptorB::
# 172 "data/maps/A0_Inicio_2/scripts.pory"
	lock
# 173 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 2
	goto_if_eq A0_Inicio_2_EventScript_InterruptorB_2
# 173 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 3
	goto_if_eq A0_Inicio_2_EventScript_InterruptorB_2
# 173 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 6
	goto_if_eq A0_Inicio_2_EventScript_InterruptorB_2
# 173 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 7
	goto_if_eq A0_Inicio_2_EventScript_InterruptorB_2
# 176 "data/maps/A0_Inicio_2/scripts.pory"
	addvar VAR_TEMP_3, 2
# 177 "data/maps/A0_Inicio_2/scripts.pory"
	playse SE_SWITCH
# 178 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_InterruptorB_Text_1, MSGBOX_DEFAULT
# 179 "data/maps/A0_Inicio_2/scripts.pory"
	call A0_Inicio_2_Script_VerificarBitmask
A0_Inicio_2_EventScript_InterruptorB_1:
# 181 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_InterruptorB_2:
# 174 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_InterruptorB_Text_0, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_InterruptorB_1


A0_Inicio_2_EventScript_InterruptorC::
# 186 "data/maps/A0_Inicio_2/scripts.pory"
	lock
# 187 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 4
	goto_if_ge A0_Inicio_2_EventScript_InterruptorC_2
# 190 "data/maps/A0_Inicio_2/scripts.pory"
	addvar VAR_TEMP_3, 4
# 191 "data/maps/A0_Inicio_2/scripts.pory"
	playse SE_SWITCH
# 192 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_InterruptorC_Text_1, MSGBOX_DEFAULT
# 193 "data/maps/A0_Inicio_2/scripts.pory"
	call A0_Inicio_2_Script_VerificarBitmask
A0_Inicio_2_EventScript_InterruptorC_1:
# 195 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_InterruptorC_2:
# 188 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_InterruptorC_Text_0, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_InterruptorC_1


A0_Inicio_2_Script_VerificarBitmask::
# 200 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_3, 7
	goto_if_eq A0_Inicio_2_Script_VerificarBitmask_2
A0_Inicio_2_Script_VerificarBitmask_1:
	return

A0_Inicio_2_Script_VerificarBitmask_2:
# 201 "data/maps/A0_Inicio_2/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 202 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_Script_VerificarBitmask_Text_0, MSGBOX_DEFAULT
# 203 "data/maps/A0_Inicio_2/scripts.pory"
	waitfanfare
# 204 "data/maps/A0_Inicio_2/scripts.pory"
	call A0_Inicio_2_Script_AplicarPuzzleResuelto
	goto A0_Inicio_2_Script_VerificarBitmask_1


A0_Inicio_2_Script_AplicarPuzzleResuelto::
	return


A0_Inicio_2_EventScript_CombateRacha::
# 214 "data/maps/A0_Inicio_2/scripts.pory"
	lock
# 215 "data/maps/A0_Inicio_2/scripts.pory"
	faceplayer
# 217 "data/maps/A0_Inicio_2/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, A0_Inicio_2_EventScript_CombateRacha_2
# 223 "data/maps/A0_Inicio_2/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_5
# 224 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CombateRacha_Text_1, MSGBOX_YESNO
# 226 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq A0_Inicio_2_EventScript_CombateRacha_5
# 232 "data/maps/A0_Inicio_2/scripts.pory"
	switch VAR_TEMP_5
# 233 "data/maps/A0_Inicio_2/scripts.pory"
	case 0, A0_Inicio_2_EventScript_CombateRacha_9
# 235 "data/maps/A0_Inicio_2/scripts.pory"
	case 1, A0_Inicio_2_EventScript_CombateRacha_10
# 238 "data/maps/A0_Inicio_2/scripts.pory"
	setwildbattle SPECIES_ABSOL, 16, ITEM_SITRUS_BERRY
A0_Inicio_2_EventScript_CombateRacha_7:
# 241 "data/maps/A0_Inicio_2/scripts.pory"
	dowildbattle
# 243 "data/maps/A0_Inicio_2/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 244 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq A0_Inicio_2_EventScript_CombateRacha_13
# 258 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_5, 0
# 259 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CombateRacha_Text_5, MSGBOX_DEFAULT
A0_Inicio_2_EventScript_CombateRacha_12:
# 262 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_CombateRacha_2:
# 218 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CombateRacha_Text_0, MSGBOX_DEFAULT
# 219 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_CombateRacha_5:
# 227 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CombateRacha_Text_2, MSGBOX_DEFAULT
# 228 "data/maps/A0_Inicio_2/scripts.pory"
	release
	end

A0_Inicio_2_EventScript_CombateRacha_9:
# 234 "data/maps/A0_Inicio_2/scripts.pory"
	setwildbattle SPECIES_ZIGZAGOON, 10, ITEM_NONE
	goto A0_Inicio_2_EventScript_CombateRacha_7

A0_Inicio_2_EventScript_CombateRacha_10:
# 236 "data/maps/A0_Inicio_2/scripts.pory"
	setwildbattle SPECIES_ELECTRIKE, 13, ITEM_ORAN_BERRY
	goto A0_Inicio_2_EventScript_CombateRacha_7

A0_Inicio_2_EventScript_CombateRacha_13:
# 245 "data/maps/A0_Inicio_2/scripts.pory"
	addvar VAR_TEMP_5, 1
# 246 "data/maps/A0_Inicio_2/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_5
# 248 "data/maps/A0_Inicio_2/scripts.pory"
	compare VAR_TEMP_5, 3
	goto_if_ge A0_Inicio_2_EventScript_CombateRacha_16
# 255 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CombateRacha_Text_4, MSGBOX_DEFAULT
	goto A0_Inicio_2_EventScript_CombateRacha_12

A0_Inicio_2_EventScript_CombateRacha_16:
# 249 "data/maps/A0_Inicio_2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 250 "data/maps/A0_Inicio_2/scripts.pory"
	msgbox A0_Inicio_2_EventScript_CombateRacha_Text_3, MSGBOX_DEFAULT
# 251 "data/maps/A0_Inicio_2/scripts.pory"
	waitfanfare
# 252 "data/maps/A0_Inicio_2/scripts.pory"
	giveitem ITEM_NUGGET, 1
# 253 "data/maps/A0_Inicio_2/scripts.pory"
	setvar VAR_TEMP_5, 0
	goto A0_Inicio_2_EventScript_CombateRacha_12


A0_Inicio_2_Script_CurarEquipoConEfecto::
# 267 "data/maps/A0_Inicio_2/scripts.pory"
	fadescreen FADE_TO_BLACK
# 268 "data/maps/A0_Inicio_2/scripts.pory"
	playfanfare MUS_HEAL
# 269 "data/maps/A0_Inicio_2/scripts.pory"
	waitfanfare
# 270 "data/maps/A0_Inicio_2/scripts.pory"
	special HealPlayerParty
# 271 "data/maps/A0_Inicio_2/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


# 285 "data/maps/A0_Inicio_2/scripts.pory"

# 286 "data/maps/A0_Inicio_2/scripts.pory"
.align 2

# 147 "data/maps/A0_Inicio_2/scripts.pory"
A0_Inicio_2_EventScript_TriggerAviso_Movement_0:
# 147 "data/maps/A0_Inicio_2/scripts.pory"
	emote_exclamation_mark
	step_end

A0_Inicio_2_EventScript_NpcKitPruebas_Text_0:
# 24 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Equipo curado y PP restaurados!$"

A0_Inicio_2_EventScript_NpcKitPruebas_Text_1:
# 32 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Avisame cuando quieras activar el kit.$"

A0_Inicio_2_EventScript_NpcKitPruebas_Text_2:
# 37 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Elige tu Pokemon de pruebas:$"

A0_Inicio_2_EventScript_NpcKitPruebas_Text_3:
# 40 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Mudkip (Nv.15)$"

A0_Inicio_2_EventScript_NpcKitPruebas_Text_4:
# 41 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Treecko (Nv.15)$"

A0_Inicio_2_EventScript_NpcKitPruebas_Text_5:
# 42 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Torchic (Nv.15)$"

A0_Inicio_2_EventScript_NpcKitPruebas_Text_6:
# 60 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Kit activado! Recibiste tu Pokemon,\nPokedex y Zapatillas Deportivas.$"

A0_Inicio_2_EventScript_NpcContador_Text_0:
# 80 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Primera charla ({STR_VAR_1}).\nVAR_TEMP_2 se mantendra mientras\nno salgas de A0_Inicio_2.$"

A0_Inicio_2_EventScript_NpcContador_Text_1:
# 82 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Llevas {STR_VAR_1} charlas. Sigue asi!$"

A0_Inicio_2_EventScript_NpcContador_Text_2:
# 84 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Hito de {STR_VAR_1} charlas alcanzado!\nToma una Superpocion de regalo.$"

A0_Inicio_2_EventScript_NpcContador_Text_3:
# 87 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Limite de {STR_VAR_1} alcanzado.\nReiniciando contador a 0.$"

A0_Inicio_2_EventScript_NpcContador_Text_4:
# 90 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Contador actual: {STR_VAR_1} / 10.$"

A0_Inicio_2_EventScript_CartelMenu_Text_0:
# 99 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Panel de control de A0_Inicio_2.\nSelecciona una herramienta:$"

A0_Inicio_2_EventScript_CartelMenu_Text_1:
# 103 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Curar equipo$"

A0_Inicio_2_EventScript_CartelMenu_Text_2:
# 104 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Clima: Lluvia$"

A0_Inicio_2_EventScript_CartelMenu_Text_3:
# 105 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Clima: Tormenta Arena$"

A0_Inicio_2_EventScript_CartelMenu_Text_4:
# 106 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Clima: Despejado$"

A0_Inicio_2_EventScript_CartelMenu_Text_5:
# 107 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Resetear VAR_TEMP$"

A0_Inicio_2_EventScript_CartelMenu_Text_6:
# 114 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Equipo curado al maximo!$"

A0_Inicio_2_EventScript_CartelMenu_Text_7:
# 119 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Clima cambiado a lluvia.$"

A0_Inicio_2_EventScript_CartelMenu_Text_8:
# 124 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Clima cambiado a tormenta de arena.$"

A0_Inicio_2_EventScript_CartelMenu_Text_9:
# 129 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Clima despejado.$"

A0_Inicio_2_EventScript_CartelMenu_Text_10:
# 137 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Todas las variables temporales\ndel mapa han vuelto a 0.$"

A0_Inicio_2_EventScript_TriggerAviso_Text_0:
# 150 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Has activado el Coord Event!\nVAR_TEMP_1 pasa a valer 1,\nasi que no volvera a saltar.$"

A0_Inicio_2_EventScript_InterruptorA_Text_0:
# 160 "data/maps/A0_Inicio_2/scripts.pory"
	.string "El interruptor A ya esta encendido.$"

A0_Inicio_2_EventScript_InterruptorA_Text_1:
# 164 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Interruptor A activado!$"

A0_Inicio_2_EventScript_InterruptorB_Text_0:
# 174 "data/maps/A0_Inicio_2/scripts.pory"
	.string "El interruptor B ya esta encendido.$"

A0_Inicio_2_EventScript_InterruptorB_Text_1:
# 178 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Interruptor B activado!$"

A0_Inicio_2_EventScript_InterruptorC_Text_0:
# 188 "data/maps/A0_Inicio_2/scripts.pory"
	.string "El interruptor C ya esta encendido.$"

A0_Inicio_2_EventScript_InterruptorC_Text_1:
# 192 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Interruptor C activado!$"

A0_Inicio_2_Script_VerificarBitmask_Text_0:
# 202 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Los 3 interruptores estan activos!\nMecanismo desbloqueado.$"

A0_Inicio_2_EventScript_CombateRacha_Text_0:
# 218 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Necesitas un Pokemon antes de combatir.\nHabla con el muñeco Regirock!$"

A0_Inicio_2_EventScript_CombateRacha_Text_1:
# 224 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Racha actual en la sala: {STR_VAR_1}.\nQuieres iniciar un combate de prueba?$"

A0_Inicio_2_EventScript_CombateRacha_Text_2:
# 227 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Vuelve cuando quieras entrenar.$"

A0_Inicio_2_EventScript_CombateRacha_Text_3:
# 250 "data/maps/A0_Inicio_2/scripts.pory"
	.string "3 victorias seguidas!\nToma una Pepita y reiniciamos racha.$"

A0_Inicio_2_EventScript_CombateRacha_Text_4:
# 255 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Victoria! Racha actual: {STR_VAR_1} de 3.$"

A0_Inicio_2_EventScript_CombateRacha_Text_5:
# 259 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Has huido o perdido.\nTu racha vuelve a 0.$"

Text_KitBienvenida::
# 275 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Bienvenido al mapa de pruebas!\n"
	.string "Quieres activar el kit de desarrollo?$"

Text_KitYaActivo::
# 280 "data/maps/A0_Inicio_2/scripts.pory"
	.string "Ya tienes tu equipo activo.\n"
	.string "Quieres curar a tus Pokemon?$"
