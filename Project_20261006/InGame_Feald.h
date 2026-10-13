#pragma once
#include"InGame_Bass.h"

class Feald:public InGameState
{
	//	プレイヤーのマップ上の座標
	int playerX = 1;
	int playerY = 1;

	//	マップの描画
	void DrawMap();

public:
	Feald() {};
	~Feald() {};
	
	void OnEnter();
	void OnUpdate();
	void OnExit();

};