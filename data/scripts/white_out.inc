EventScript_AfterWhiteOutHeal:: @ 81A8D97
	lockall
	textcolor 1
	msgbox Text_FirstShouldRestoreMonsHealth
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	call_if_unset FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsgPreBrock
	call_if_set FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsg
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_AfterWhiteOutHealMsgPreBrock:: @ 81A8DC6
	msgbox Text_MonsHealedShouldBuyPotions
	return

EventScript_AfterWhiteOutHealMsg:: @ 81A8DCF
	msgbox Text_MonsHealed
	return

EventScript_AfterWhiteOutMomHeal:: @ 81A8DD8
	lockall
	textcolor 1
	applymovement 1, Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Text_HadQuiteAnExperienceTakeRest
	call EventScript_OutOfCenterPartyHeal
	msgbox Text_MomExplainHPGetPotions
	fadedefaultbgm
	releaseall
	end

EventScript_FieldPoison:: @ 81A8DFD
	lockall
	textcolor 3
	special TryFieldPoisonWhiteOut
	waitstate
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_FieldWhiteOut
	releaseall
	end

EventScript_FieldWhiteOut:: @ 81A8E11
	checkmoney 1, 0
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_FieldWhiteOutNoMoney
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_FieldWhiteOutHasMoney
	end

EventScript_FieldWhiteOutNoMoney:: @ 81A8E2E
	msgbox Text_WhitedOut
	goto EventScript_FieldWhiteOutFade
	end

EventScript_FieldWhiteOutHasMoney:: @ 81A8E3C
	special Special_OverworldWhiteOutGetMoneyLoss
	msgbox Text_WhitedOutLostMoney
	goto EventScript_FieldWhiteOutFade
	end

EventScript_FieldWhiteOutFade:: @ 81A8E4D
	special Script_FadeOutMapMusic
	waitstate
	fadescreen FADE_TO_BLACK
	special SetCB2Whiteout
	waitstate
	end
