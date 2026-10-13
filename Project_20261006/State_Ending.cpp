#include<conio.h>
#include"State_Ending.h"
#include"GameManager.h"
#include"State_Title.h"

void State_Ending::OnEnter(GameManager* manager)
{
	std::cout << "エンディング" << std::endl;
}

void State_Ending::OnUpdate(GameManager* manager, float deltaTime)
{

	std::cout << "キーを押してタイトルへ戻る\n";
	//	AnyKeyでタイトルに遷移
	if(_kbhit())
	{
		int ch = _getch();
		manager->ChangeState(std::make_unique<State_Title>());
	}
}

void State_Ending::OnExit(GameManager* manager)
{
	std::cout << "エンディングの終了" << std::endl;
}

const std::string State_Ending::GetName()const
{
	return "Ending";
}