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
	//	AnyKey‚ÅƒQ[ƒ€‰æ–Ê“ú‘JˆÚ
	if (_kbhit())
	{
		int ch = getch();
		manager->ChangeState(std::make_unique<State_InGame>());
	}
}

void State_Title::OnExit(GameManager* manager)
{
	
}

const std::string State_Title::GetName()const
{
	return "Title";
}