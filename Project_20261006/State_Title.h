#pragma once
#include"GameState.h"

class GameManager;

//	ƒ^ƒCƒgƒ‹‰æ–Ê
class State_Title :public GameState
{
public:
	void OnEnter(GameManager* manager);
	void OnUpdate(GameManager* manager, float deltaTime);
	void OnExit(GameManager* manager);
	const std::string GetName()const;
};
