#pragma once

//	敵のデータを表す構造体
struct EnemyData
{
	int ID;
	const char Name[256];
	int HP;
	int ATK;
	int DEF;
	int SPD;
	int Gold;
	int EXP;
	float CriticalRate;
};

//	プレイヤーのデータを表す構造体
struct PlayerData
{
	int ID;
	int Name[256];
	int HP;
	int ATK;
	int DEF;
	int SPD;
	float CriticalRate;
};