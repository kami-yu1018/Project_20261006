#include<conio.h>
#include"State_Title.h"
#include"GameManager.h"
#include"State_InGame.h"

void State_Title::OnEnter(GameManager* manager)
{
	std::cout << "title" << std::endl;
}

void State_Title::OnUpdate(GameManager* manager, float deltaTime)
{
	//	AnyKeyでゲーム画面日遷移
	if (_kbhit())
	{
		int ch = _getch();
		manager->ChangeState(std::make_unique<State_InGame>());
	}
}

void State_Title::OnExit(GameManager* manager)
{
	std::cout << "タイトル画面の終了" << std::endl;
}

const std::string State_Title::GetName()const
{
	return "Title";
}