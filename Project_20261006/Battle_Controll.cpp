#include"Battle_Controll.h"
#include"Player.h"

BattleControll::BattleControll()
{
	model.PlayerEnter();
}

void BattleControll::OnEnter()
{
	model.EnemyEnter();
	//	戦闘開始時、前の戦闘で味方が死んでいたらHP１で復活させる
	for (int i = 0; i < 4; ++i)
	{
		model.PlayerRebarth(i);
	}
}

void BattleControll::OnUpdate()
{
	std::unique_ptr<Player>player[4];
	std::unique_ptr<Enemy>enemy[3];
	for (int i = 0; i < 4; ++i)
	{
		player[i] = std::make_unique<Player>(model.GetPlayer(i));
	}
	for (int i = 0; i < 3; ++i)
	{
		enemy[i] = std::make_unique<Enemy>(model.GetEnemy(i));
	}

	//	味方のコマンド
	for (int i = 0; i < 4; ++i)
	{

		if (GameEnd() > 0)
			break;

		model.StateChangeDefault(i);

		//	生きていたら実行
		if (model.CheckAlive(i))
		{
			std::cout << player[i]->Data.Name << "はどうする？\n";
			std::cout << "１：攻撃　２：防御　３：スキル\n";

			switch (model.InputKey())
			{
			case '1':
				model.Attack(i);
				break;

			case'2':
				model.Gard(i);
				break;
			case'3':
				model.Skill(i);
				break;
			}





		}
	}
}

void BattleControll::OnExit()
{

}

int BattleControll::GameEnd()
{
	return model.BattleEnd();
}
