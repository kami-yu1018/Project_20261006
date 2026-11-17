#pragma once

#include<iostream>
#include<memory>
#include"Player.h"
#include"Enemy.h"

class BattleModel
{
	std::unique_ptr<Enemy>enemy[3] = {};		//	敵
	std::unique_ptr<Player>player[4] = {};		//	プレイヤー
	bool enemyAlive[3] = { 1,1,1 };				//	敵の生存状況
	bool playerAlive[4] = { 1,1,1,1 };			//	プレイヤーの生存状況

	//	デフォルトステータス
	int playerBassATK[4] = {};
	int playerBassDEF[4] = {};

public:

	void PlayerEnter();		//	プレイヤーの初期化生成
	void EnemyEnter();		//	敵の初期化生成

	int InputKey();			//	キー入力処理

	void Attack(int i);		//	通常攻撃
	void Gard(int i);		//	ガード
	void Skill(int i);		//	スキル

	void StateChangeDefault(int i);	//	ステータスをデフォルトに戻す処理

	void PlayerRebarth(int i);		//	プレイヤーが死んでいた場合次の戦闘でHP1で復活させる処理

	bool CheckAlive(int i);			//	死亡しているかどうか

	void PlayerDead(int i);			//	プレイヤー死亡時の処理
	void EnemyDead(int i);			//	敵死亡時の処理

	int BattleEnd();		//	バトル終了

	Player GetPlayer(int i);	//	プレイヤー情報の取得
	Enemy GetEnemy(int i);		//	敵情報の取得
};