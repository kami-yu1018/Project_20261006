#include"Battle_Model.h"
#include"Factory.h"
#include"Key.h"
#include"math.h"

//	プレイヤーの初期化生成処理
void BattleModel::PlayerEnter()
{
	//	プレイヤーの生成
	for (int i = 0; i < 4; ++i)
	{
		player[i] = std::make_unique<Player>(PlayerFactory::CreatePlayer(i + 1));
		playerBassATK[i] = player[i]->Data.ATK;
		playerBassDEF[i] = player[i]->Data.DEF;
	}
}

//	敵の初期化生成処理
void BattleModel::EnemyEnter()
{
	for (int i = 0; i < 3; ++i)
	{
		enemyAlive[i] = true;
		enemy[i] = std::make_unique<Enemy>(EnemyFactory::CreateEnemy(i + 1));
		std::cout << enemy[i]->Data.Name << "が現れた！\n";
	}
}

//	キー入力処理
int InputKey()
{
	const int command = ReadValidKey("123");
	return command;
}

//	プレイヤーの行動
//	通常攻撃
void BattleModel::Attack(int i)
{
	std::cout << "ターゲットを選択してください" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		if (enemyAlive[i])
		{
			std::cout << i + 1 << "：" << enemy[i]->Data.Name;
		}
	}

	std::cout << std::endl;

	//	ターゲット選択
	int target = ReadValidKey("123");

	while (!enemyAlive[target - '1'])
	{
		target = ReadValidKey("123");
	}

	int tag = target - '1';


	//	ダメージ計算
	DamageResult result = CalculateDamage(
		player[i]->Data.ATK,
		player[i]->Data.CriticalRate,
		enemy[tag]->Data.DEF);

	enemy[tag]->Data.HP -= result.damage;

	//	テキスト
	std::cout << player[i]->Data.Name << "の攻撃！\n";
	if (result.isCritical)
	{
		std::cout << "クリティカルヒット！\n";
	}
	std::cout << enemy[tag]->Data.Name << "に" << result.damage << "ダメージ！\n";
}

//	ガード
void BattleModel::Gard(int i)
{
	//	防御力を1.5倍に
	player[i]->Data.DEF *= 1.5;

	//	テキスト
	std::cout << player[i]->Data.Name << "は防御態勢を取った！\n";
}

//	スキル
void BattleModel::Skill(int i)
{
	int target;
	int tag;
	switch (i)
	{
	case 0:		//	剣士
		std::cout << player[i]->Data.Name << "の必殺斬！\n";
		for (int ene = 0; ene < 3; ++ene)
		{
			if (enemyAlive[i])
			{
				DamageResult result = CalculateDamage(
					player[i]->Data.ATK,
					player[i]->Data.CriticalRate,
					enemy[ene]->Data.DEF);

				enemy[ene]->Data.HP -= result.damage;

				if (result.isCritical)
				{
					std::cout << "クリティカルヒット！\n";
				}

				std::cout << enemy[ene]->Data.Name << "に" << result.damage << "ダメージ！\n";
			}
		}
		break;

	case 1:		//	魔法使い
		std::cout << "ターゲットを選択してください" << std::endl;
		for (int i = 0; i < 3; ++i)
		{
			if (enemyAlive[i])
			{
				std::cout << i + 1 << "：" << enemy[i]->Data.Name;
			}
		}
		std::cout << "\n";

		target = ReadValidKey("123");

		while (!enemyAlive[target - '1']) target = ReadValidKey("123");

		tag = target - '1';

		player[i]->Data.ATK *= 1.5f;

		DamageResult result = CalculateDamage
		(
			player[i]->Data.ATK,
			player[i]->Data.CriticalRate,
			enemy[tag]->Data.DEF
		);
		enemy[tag]->Data.HP -= result.damage;

		std::cout << player[i]->Data.Name << "のファイアボール！\n";
		std::cout << enemy[tag]->Data.Name << "に" << result.damage << "ダメージ！\n";
		break;

	case 2:		//	賢者
		//	選択した味方の体力を回復

		std::cout << "ターゲットを選択してください" << std::endl;
		for (int i = 0; i < 4; ++i)
		{
			if (enemyAlive[i])
			{
				std::cout << i + 1 << "：" << player[i]->Data.Name;
			}
		}
		std::cout << "\n";

		target = ReadValidKey("1234");

		while (!playerAlive[target - '1'])
		{
			target = ReadValidKey("1234");
		}

		tag = target - '1';

		player[tag]->Data.HP += player[i]->Data.DEF * 2;
		std::cout << player[i]->Data.Name << "のヒール！\n";
		std::cout << player[tag]->Data.Name << "のＨＰが" << player[i]->Data.DEF * 2 << "回復！\n";
		break;

	case 3:
		std::cout << player[i]->Data.Name << "のかまいたち！\n";

		//	ランダムに4回攻撃
		for (int atk = 0; atk < 4; ++atk)
		{
			int tag = rand() % 3;

			while (!enemyAlive[tag])
			{
				tag = rand() % 3;
			}

			DamageResult result = CalculateDamage(
				player[i]->Data.ATK,
				player[i]->Data.CriticalRate,
				enemy[tag]->Data.DEF);

			enemy[tag]->Data.HP -= result.damage;

			std::cout << enemy[tag]->Data.Name << "に" << result.damage << "ダメージ！\n";
		}
		std::cout << "\n";
		break;
	}
}

//	ステータスをデフォルトに戻す処理
void BattleModel::StateChangeDefault(int i)
{
	player[i]->Data.ATK = playerBassATK[i];
	player[i]->Data.DEF = playerBassDEF[i];
}

//	レイヤーが死んでいた場合次の戦闘でHP1で復活させる処理
void BattleModel::PlayerRebarth(int i)
{
	if (!playerAlive[i])
	{
		player[i]->Data.HP = 1;
		playerAlive[i] = true;
	}
}

//	
bool BattleModel::CheckAlive(int i)
{
	if (!playerAlive[i])
	{
		return false;
	}

	return true;
}

void BattleModel::PlayerDead(int i)
{
	if (player[i]->Data.HP <= 0)
	{
		playerAlive[i] = false;
		std::cout << player[i]->Data.Name << "は倒れた！\n";
	}
}

void BattleModel::EnemyDead(int i)
{
	if (enemy[i]->Data.HP <= 0 && enemyAlive[i] == 1)
	{
		enemyAlive[i] = 0;
		std::cout << enemy[i]->Data.Name << "は倒れた！\n";
	}
}

//	バトル終了処理
int BattleModel::BattleEnd()
{
	//	敵が全滅しているか確認
	bool allEnemiesDead = true;

	for (int i = 0; i < 3; ++i)
	{
		if (enemyAlive[i] && enemy[i]->Data.HP > 0)
		{
			allEnemiesDead = false;
			break;
		}
	}

	//	敵が全滅したら１を返す（勝利）
	if (allEnemiesDead)
	{
		return 1;
	}

	//	味方が全滅しているか確認
	bool allPlayersDead = true;

	for (int i = 0; i < 4; ++i)
	{
		if (playerAlive[i] && player[i]->Data.HP > 0)
		{
			allPlayersDead = false;
			break;
		}
	}

	//	味方が全滅したら２を返す（ゲームオーバー）
	if (allPlayersDead)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

Player BattleModel::GetPlayer(int i)
{
    return *player[i];
}

Enemy BattleModel::GetEnemy(int i)
{
    return *enemy[i];
}