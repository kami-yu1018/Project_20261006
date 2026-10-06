#include"Factory.h"
#include"Enemy.h"
#include"Player.h"

//------------------------------------------------------
//	敵
//------------------------------------------------------
//	データテーブル設定
const EnemyData EnemyFactory::EnemyTable[] =
{
	{1,"スライム",10,5,2,1,10,5,0.01f},
	{2,"ゴブリン",20,10,5,2,20,10,0.03},
	{3,"オーク",30,15,8,3,30,15,0.05},
};

//	データテーブルサイズの計測
const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

Enemy* EnemyFactory::CreateEnemy(int ID)
{
	for (int i = 0; i < EnemyTableSize; ++i)
	{
		if (EnemyTable[i].ID == ID)
		{
			return new Enemy(EnemyTable[i]);
		}
	}
	return nullptr;
}

//------------------------------------------------------
// プレイヤー
//------------------------------------------------------
const PlayerData PlayerFactory::PlayerTable[] =
{
	{1,"剣士",28,12,8,3,0,0.03},
	{2,"魔導士",18, 16,3,2,0.03},
	{3,"賢者",24,11,6,2,0.01},
	{4,"盗賊",22,10,5,5, 0.05},
};

const int PlayerFactory::PlayerTableSize = sizeof(PlayerTable) / sizeof(PlayerData);

Player* PlayerFactory::CreatePlayer(int ID)
{
	for (int i = 0; i < PlayerTableSize; ++i)
	{
		if (PlayerTable[i].ID == ID)
		{
			return new Player(PlayerTable[i]);
		}
	}
	return nullptr;
}