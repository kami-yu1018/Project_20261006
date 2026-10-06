#pragma once
#include<iostream>
#include<memory>

class GameState;

//	ゲーム管理クラス
class GameManager
{
	std::unique_ptr<GameState>currentState;
	bool isRunning;
	float GameTime;
public:
	GameManager(std::unique_ptr<GameState>initialState);	//	コンストラクタ
	void ChangeState(std::unique_ptr<GameState>newState);	//	場面の変更
	void Update(float deltaTime);
};
