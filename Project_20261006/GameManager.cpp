#include"GameManager.h"
#include"GameState.h"

//	コンストラクタ作動時にcurrentStateを初期化sることでChangeStateにあった一部のコードを不要にする
GameManager::GameManager(std::unique_ptr<GameState>initialState)
	:isRunning(true),GameTime(0.0f),currentState(std::move(initialState))
{
	currentState->OnEnter(this);
}

//	次のステートに移行時、使用する
void GameManager::ChangeState(std::unique_ptr<GameState>newState)
{
	currentState->OnExit(this);				//	終了処理
	currentState = std::move(newState);		//	新しいステートを変数ににムーブ
	currentState->OnEnter(this);			//	初期化処理
}

//	更新
void GameManager::Update(float deltaTime)
{
	GameTime += deltaTime;		//	前回の時間からどれくらいたっているかを加算
	if (currentState)
	{
		currentState->OnUpdate(this, deltaTime);
	}
}