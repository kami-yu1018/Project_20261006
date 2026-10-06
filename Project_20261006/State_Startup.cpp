#include"State_Startup.h"
#include"GameManager.h"
#include"State_Title.h"

void State_Startup::OnEnter(GameManager* manager)
{
	std::cout << "スタートアップ処理" << std::endl;
}

void State_Startup::OnUpdate(GameManager* manager, float deltaTime)
{
	manager->ChangeState(std::make_unique<State_Title>());

}

void State_Startup::OnExit(GameManager* manager)
{
	std::cout << "スタートアップ処理の終了" << std::endl;
}

const std::string State_Startup::GetName()const
{
	return"Startup";
}