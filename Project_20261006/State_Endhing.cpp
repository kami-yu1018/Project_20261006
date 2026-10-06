#include<conio.h>
#include"State_Endhing.h"
#include"GameManager.h"
#include"State_Title.h"

void State_Endhing::OnEnter(GameManager* manager)
{
	std::cout << "エンディング" << std::endl;
}

void State_Endhing::OnUpdate(GameManager* manager, float deltaTime)
{
	//	AnyKeyでタイトルに遷移
	if(_kbhit)
	{
		int ch = _getch();
		manager->ChangeState(std::make_unique<State_Title>());
	}
}

void State_Endhing::OnExit(GameManager* manager)
{
	std::cout << "エンディングの終了" << std::endl;
}

const std::string State_Endhing::GetName()const
{
	return "Endhing";
}