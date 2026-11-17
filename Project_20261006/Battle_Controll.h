#pragma once
#include"Battle_Model.h"

class BattleControll
{
	BattleModel model;

public:
	BattleControll();	//	コンストラクター

	void OnEnter();		//	初期化
	void OnUpdate();	//	更新
	void OnExit();		//	終了

	int GameEnd();		//	バトルの終わり

};