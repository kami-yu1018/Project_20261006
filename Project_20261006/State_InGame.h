#pragma once
#include"GameState.h"
#include"InGame_Batttle.h"

class GameManager;

//	ƒQ[ƒ€‰æ–Ê
class State_InGame :public GameState
{
	int battlenum = 1;

	Battle battle;

public:
	void OnEnter(GameManager* manager);
	void OnUpdate(GameManager* manager, float deltaTime);
	void OnExit(GameManager* manager);
	const std::string GetName()const;
};
