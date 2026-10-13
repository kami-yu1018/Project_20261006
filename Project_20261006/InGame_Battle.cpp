#include"InGame_Batttle.h"
#include"Key.h"
#include"math.h"

Battle::Battle()
{
	PlayerEnter();
}

//	初期化処理
void Battle::OnEnter()
{
	EnemyEnter();
	std::cout << std::endl;
}

//	プレイヤー初期化生成処理
//	ゲーム1ループにつき１回しか作動しない（その後はステータスを引き継ぐため）
void Battle::PlayerEnter()
{
	//	プレイヤーの生成
	for (int i = 0; i < 4; ++i)
	{
		player[i] = PlayerFactory::CreatePlayer(i + 1);
		P_bassATK[i] = player[i]->Data.ATK;
		P_bassDEF[i] = player[i]->Data.DEF;
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
		//	最初にデフォルトステータスに戻す
		player[i]->Data.ATK = P_bassATK[i];
		player[i]->Data.DEF = P_bassDEF[i];

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
				Attack(i);
				break;

			//	防御
			case '2':	
				Gard(i);
				break;

			//	スキル
			case '3':
				Skill(i);
				break;
			}
			//	敵の死亡判定
			for (int ene = 0; ene < 3; ++ene)
			{
				if (enemy[ene]->Data.HP <= 0 && e_alive[ene] == 1)
				{
					e_alive[ene] = 0;
					std::cout << enemy[ene]->Data.Name << "は倒れた！\n";
				}
			}
			
			std::cout << std::endl;
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

void Battle::OnExit()
{
	
}

//	通常攻撃
void Battle::Attack(int i)
{
	std::cout << "ターゲットを選択してください" << std::endl;
	std::cout << "１：" << enemy[0]->Data.Name <<
		"２：" << enemy[1]->Data.Name <<
		"３：" << enemy[2]->Data.Name << std::endl;

	//	ターゲット選択
	const int target = ReadValidKey("123");
	int tag;
	if (target == '1')
	{
		tag = 0;
	}
	else if (target == '2')
	{
		tag = 1;
	}
	else if (target == '3')
	{
		tag = 2;
	}

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
void Battle::Gard(int i)
{
	//	防御力を1.5倍に
	player[i]->Data.DEF *= 1.5;
	
	//	テキスト
	std::cout << player[i]->Data.Name << "は防御態勢を取った！\n";
}

//	スキル
void Battle::Skill(int i)
{
	int target_2;
	int tag;
	switch (i)
	{
	case 0:		//	剣士
		std::cout << player[i]->Data.Name << "の必殺斬！\n";
		for (int ene = 0; ene < 3; ++ene)
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
		break;
	case 1:
		std::cout << "ターゲットを選択してください" << std::endl;
		std::cout << "１：" << enemy[0]->Data.Name
			<< "２：" << enemy[1]->Data.Name
			<< "３：" << enemy[2]->Data.Name << std::endl;

		target_2 = ReadValidKey("123");
		if (target_2 == '1')	tag = 0;
		else if (target_2 == '2')	tag = 1;
		else if (target_2 == '3')	tag = 2;
		std::cout << player[i]->Data.Name << "のファイアボール！\n";
		player[i]->Data.ATK *= 1.5f;

		DamageResult result = CalculateDamage
		(
			player[i]->Data.ATK,
			player[i]->Data.CriticalRate,
			enemy[tag]->Data.DEF
		);
		enemy[tag]->Data.HP -= result.damage;

		std::cout << enemy[tag]->Data.Name << "に" << result.damage << "ダメージ！\n";
		break;
	case 2:
		//	選択した味方の体力を回復

		std::cout << "ターゲットを選択してください" << std::endl;
		std::cout << "１：" << player[0]->Data.Name<<
			"　２：" << player[1]->Data.Name <<
			"　３：" << player[2]->Data.Name <<
			"　４：" << player[3]->Data.Name << std::endl;
		target_2 = ReadValidKey("1234");
		int tag;
		if (target_2 == '1')
		{
			tag = 0;
		}
		else if (target_2 == '2')
		{
			tag = 1;
		}
		else if (target_2 == '3')
		{
			tag = 2;
		}
		else if (target_2 == '4')
		{
			tag = 3;
		}

		player[tag]->Data.HP += player[i]->Data.DEF * 2;
		std::cout << player[i]->Data.Name << "のヒール！\n";
		std::cout << player[tag]->Data.Name << "のＨＰが" << player[i]->Data.DEF * 2 << "回復！\n";
		break;
	case 3:
		std::cout << player[i]->Data.Name << "のかまいたち！\n";

		//	ランダムに4回攻撃
		for (int atk = 0; atk < 4; ++atk)
		{
			const int tag = rand() % 3;
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