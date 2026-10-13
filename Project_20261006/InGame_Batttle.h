#pragma once

#include<iostream>
#include<conio.h>
#include"Factory.h"
#include"Player.h"
#include"Enemy.h"
#include"math.h"

class Battle
{
	Enemy* enemy[3] = {};
	bool e_alive[3] = { 1,1,1 };
	Player* player[4] = {};
	bool p_alive[4] = { 1,1,1,1 };

	//	デフォルトステータスに戻す用の変数
	int P_bassATK[4] = {};
	int P_bassDEF[4] = {};

public:
	Battle();
	~Battle() {};

	void OnEnter(int battlenum);
	void OnUpdate();
	void OnExit();

	void PlayerEnter();
	void EnemyEnter();


	void Attack(int i);
	void Gard(int i);
	void Skill(int i);

	
};