#pragma once
#include"GameState.h"

class GameManager;

//	エンディング画面
class State_Ending:public GameState
{
public:
	void OnEnter(GameManager* manager);
	void OnUpdate(GameManager* manager, float deltaTime);
	void OnExit(GameManager* manager);
	const std::string GetName()const;
};
