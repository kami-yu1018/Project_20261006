#pragma once
#include"InGame_Bass.h"

class Feald:public InGameState
{
	//	プレイヤーのマップ上の座標
	int playerX = 1;
	int playerY = 1;

	//	敵とエンカウントしたかどうか
	bool encounter = false;

	

public:
	//	ゴールしたかどうか
	bool Goal = false;

	Feald() {};
	~Feald() {};
	
	void OnEnter()override;
	void OnUpdate()override;
	void OnExit()override;

	//	マップの描画
	void DrawMap()const;

	//	敵にエンカウントしたかを取得
	bool Encount()const;
};