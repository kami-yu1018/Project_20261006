#pragma once
#include"GameState.h"

class GameManager;

//	ƒQ[ƒ€‰æ–Ê
class State_InGame :public GameState
{
public:
	void OnEnter(GameManager* manager);
	void OnUpdate(GameManager* manager, float deltaTime);
	void OnExit(GameManager* manager);
	const std::string GetName()const;
};
