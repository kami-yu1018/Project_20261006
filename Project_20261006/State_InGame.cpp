#include<conio.h>
#include"State_InGame.h"
#include"GameManager.h"
#include"State_Ending.h"

void State_InGame::OnEnter(GameManager* manager)
{
	//	初期化処理
	inBattle = false;
	feald.OnEnter();
}

void State_InGame::OnUpdate(GameManager* manager, float deltaTime)
{
	if (!inBattle)
	{
		//	フィールド移動
		feald.OnUpdate();
		//	敵に遭遇したらバトル開始
		if (feald.Encount())
		{
			inBattle = true;
			battle.OnEnter();
		}

		if (feald.Goal)
		{
			std::cout << "ゲームクリア！\n";
			manager->ChangeState(std::make_unique<State_Ending>());
		}
	}
	else
	{
		battle.OnUpdate();

		//	バトル終了判定
		const int result = battle.GameEnd();
		
		if (battle.GameEnd() == 1)	//	勝利：フィールドへ戻る
		{
			battle.OnExit();
			inBattle = false;

			//	マップの再表示
			std::system("cls");
			feald.DrawMap();

			std::cout << "勝利！\n";
		}
		else if (battle.GameEnd() == 2)	//	全滅：エンディング画面へ移行
		{
			std::cout << "ゲームオーバー\n";
			manager->ChangeState(std::make_unique<State_Ending>());
		}
	}

}

void State_InGame::OnExit(GameManager* manager)
{
	std::cout << "ゲーム画面の終了" << std::endl;
}

const std::string State_InGame::GetName()const
{
	return "InGame";
}