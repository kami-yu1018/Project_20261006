#include"InGame_Batttle.h"
#include"Key.h"
#include"math.h"

//	初期化処理
void Battle::OnEnter(int battlenum)
{
	EnemyEnter();
	std::cout << std::endl;

	if (battlenum == 1)
	{
		PlayerEnter();
	}
}

//	プレイヤー初期化生成処理
//	ゲーム1ループにつき１回しか作動しない（その後はステータスを引き継ぐため）
void Battle::PlayerEnter()
{
	//	プレイヤーの生成
	for (int i = 0; i < 4; ++i)
	{
		player[i] = PlayerFactory::CreatePlayer(i + 1);
	}
}

//	敵初期化生成処理
//	バトルがある度何度も呼びなおす
void Battle::EnemyEnter()
{
	for (int i = 0; i < 3; ++i)
	{
		enemy[i] = EnemyFactory::CreateEnemy(i + 1);
		std::cout << enemy[i]->Data.Name << "が現れた！\n";
	}
}

//	更新処理
void Battle::OnUpdate()
{
	//	味方のコマンド
	for (int i = 0; i < 4; ++i)
	{
		//	生きていたら実行
		if(p_alive[i]==1)
		{
			std::cout << player[i]->Data.Name << "はどうする？\n";
			std::cout << "１：攻撃　２：防御　３：スキル\n";

			const int command = ReadValidKey("123");

			switch (command)
			{
			//	通常攻撃
			case '1':
				break;
			//	防御
			case '2':
				break;
			//	スキル
			case '3':
				break;
			}
			//	敵の死亡判定
			for (int ene = 0; ene < 3; ++ene)
			{
				if (enemy[ene]->Data.HP <= 0 && e_alive[ene] == 1)
				{
					e_alive[ene] = 0;
					std::cout << enemy[ene]->Data.Name << "は倒れた！\n";
					std::cout << std::endl;
				}
			}
			
		}
		else
		{
			continue;
		}
	}

	//	敵の行動
	for (int i = 0; i < 3; ++i)
	{
		if (e_alive[i] == 1)
		{
			std::cout << enemy[i]->Data.Name << "の攻撃！\n";
			int tag = rand() % 4;
			while (p_alive[tag] == false)
			{
				tag = rand() % 4;
			}

			DamageResult result = CalculateDamage(
				enemy[i]->Data.ATK,
				enemy[i]->Data.CriticalRate,
				player[tag]->Data.DEF);

			player[tag]->Data.HP -= result.damage;

			std::cout << player[tag]->Data.Name << "に" << result.damage << "ダメージ！";
			if (player[tag]->Data.HP <= 0)
			{
				p_alive[tag] = false;
				std::cout << player[tag]->Data.Name << "は倒れた！";
			}
		}
		else
		{
			continue;
		}
	}
}

int Battle::OnExit()
{
	
}