#pragma once
#include"Data.h"

//	敵
class Enemy;
//	敵ファクトリークラス
class EnemyFactory
{
	static const EnemyData EnemyTable[];
	static const int EnemyTableSize;
public:
	static Enemy* CreateEnemy(int ID);
};

//	プレイヤー
class Player;
//	プレイヤーファクトリークラス
class PlayerFactory
{
	static const PlayerData PlayerTable[];
	static const int PlayerTableSize;
public:
	static Player* CreatePlayer(int ID);
};
