#pragma once
#include"GameState.h"
#include"InGame_Feald.h"
#include"Feald_Controll.h"
#include"InGame_Batttle.h"

class GameManager;

//	ƒQ[ƒ€‰æ–Ê
class State_InGame :public GameState
{
	FealdControll feald;
	Battle battle;

	//	ƒoƒgƒ‹ó‘Ô‚©‚Ç‚¤‚©
	bool inBattle = false;

public:
	void OnEnter(GameManager* manager)override;
	void OnUpdate(GameManager* manager, float deltaTime)override;
	void OnExit(GameManager* manager)override;
	const std::string GetName()const override;
};
