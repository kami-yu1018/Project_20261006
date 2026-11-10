#pragma once
#include<iostream>
#include<conio.h>
#include<cctype>
#include<cstdlib>

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

class FealdModel
{
	//	プレイヤーのマップ上の座標
	int playerX = 1;
	int playerY = 1;

	bool reachGoal = false;

public:
	int Move(int dx, int dy);
	bool IsGoal()const;
	bool CheckEncounter();

	int GetPlayerX()const { return playerX; }
	int GetPlayerY()const { return playerY; }
};