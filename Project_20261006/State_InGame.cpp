#include<conio.h>
#include"State_InGame.h"
#include"GameManager.h"
#include"State_Ending.h"

void State_InGame::OnEnter(GameManager* manager)
{
	//	初期化処理
}

void State_InGame::OnUpdate(GameManager* manager, float deltaTime)
{
	//	ゲーム更新処理
}

void State_InGame::OnExit(GameManager* manager)
{
	std::cout << "ゲーム画面の終了" << std::endl;
}

const std::string State_InGame::GetName()const
{
	return "InGame";
}