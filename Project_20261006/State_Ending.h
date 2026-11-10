#pragma once
#include"GameState.h"

class GameManager;

//	エンディング画面
class State_Ending:public GameState
{
	int endingResult;

public:
	State_Ending(int result);
	void OnEnter(GameManager* manager);
	void OnUpdate(GameManager* manager, float deltaTime);
	void OnExit(GameManager* manager);
	const std::string GetName()const;
};
