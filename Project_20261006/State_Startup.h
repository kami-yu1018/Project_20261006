#pragma once
#include"GameState.h"

class GameManager;

//	スタートアップ画面
class State_Startup :public GameState
{
public:
	void OnEnter(GameManager* manager);
	void OnUpdate(GameManager* manager, float deltaTime);
	void OnExit(GameManager* manager);
	const std::string GetName()const;
};
