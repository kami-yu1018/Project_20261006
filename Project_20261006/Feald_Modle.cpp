#include"Feald_Model.h"

int FealdModel::Move(int dx, int dy)
{
	int nextX = playerX + dx;
	int nextY = playerY + dy;

	//	マップの範囲外に出ないようにする
	if (nextX < 0 || nextX >= MAP_W ||
		nextY < 0 || nextY >= MAP_H)
	{
		return false;
	}

	//	壁には移動不可
	if (MAP[nextY][nextX] == 'O')
	{
		return false;
	}
	//	移動先がゴールか確認
	bool reachedGoal = (MAP[nextY][nextX] == 'G');

	//	移動を反転
	playerX = nextX;
	playerY = nextY;
}

bool FealdModel::IsGoal()const
{
	return reachGoal;
}

bool FealdModel::CheckEncounter()
{
	//	移動成功後にエンカウント判定
	if (std::rand() % 100 < ENCOUNT_RATE)
	{
		return true;
	}
	return false;
}

