#include"InGame_Feald.h"

#include<iostream>
#include<conio.h>
#include<cctype>
#include<cstdlib>

//	固定マップ
namespace
{
	const char* MAP[] =
	{
		"OOOOOOOOOOOO",
		"O      O   O",
		"O OOOO O OOO",
		"O    O   O O",
		"OOOOOO OOO O",
		"O    O     O",
		"O O      O O",
		"OOOOOOOOOOGO",
	};
	constexpr int MAP_H = sizeof(MAP) / sizeof(MAP[0]);
	constexpr int MAP_W = 12;

	constexpr int ENCOUNT_RATE = 20;
}

void Feald::OnEnter()
{
	//	プレイヤーの初期座標を設定
	playerX = 1;
	playerY = 1;

	//	初期状態はエンカウントしていない状態
	encounter = false;

	Goal = false;

	DrawMap();
}

//	更新処理
void Feald::OnUpdate()
{
	//	キーが押されるまで待機
	int key = std::tolower(_getch());
	
	int nextX = playerX;
	int nextY = playerY;
	switch (key)
	{
	case'w':
		nextY--;
		break;
	case'a':
		nextX--;
		break;
	case's':
		nextY++;
		break;
	case'd':
		nextX++;
		break;

	default:
		//	wasd以外は移動しない
		return;
	}

	//	マップの範囲外に出ないようにする
	if (nextX < 0 || nextX >= MAP_W ||
		nextY < 0 || nextY >= MAP_H)
	{
		return;
	}
	
	//	壁には移動不可
	if (MAP[nextY][nextX] == 'O')
	{
		return;
	}
	//	移動先がゴールか確認
	bool reachedGoal = (MAP[nextY][nextX] == 'G');

	//	移動を反転
	playerX = nextX;
	playerY = nextY;

	//	画面の更新
	std::system("cls");
	DrawMap();

	if (reachedGoal)
	{
		std::cout << "ゲームクリア！！！\n";
		Goal = true;
	}

	//	移動性向後におエンカウント判定
	if (std::rand() % 100 < ENCOUNT_RATE && !reachedGoal)
	{
		encounter = true;
		std::cout << "敵が現れた！";
	}
}

void Feald::OnExit()
{

}

//	マップの描画
void Feald::DrawMap()const
{
	for (int y = 0; y < MAP_H; ++y)
	{
		for (int x = 0; x < MAP_W; ++x)
		{
			//	プレイヤーの位置に記号を表示
			if (x == playerX && y == playerY)
			{
				std::cout << 'P';
			}
			else
			{
				std::cout << MAP[y][x];
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	std::cout << "移動　Ｗ：上　Ａ：左　Ｓ：下　Ｄ：右\n";
	std::cout << "G：ゴール\n";
}

bool Feald::Encount()const
{
	return encounter;
}