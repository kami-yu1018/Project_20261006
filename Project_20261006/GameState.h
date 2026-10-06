#pragma once
#include<string>

class GameManager;

//	状態規定クラス（純粋仮想クラス）
class GameState
{
public:
	virtual ~GameState() = default;	//	デストラクタ
	virtual void OnEnter(GameManager* manager) = 0;
	virtual void OnUpdate(GameManager* manager,float deltaTime) = 0;
	virtual void OnExit(GameManager* manager) = 0;
	virtual const std::string GetName() const = 0;
};
