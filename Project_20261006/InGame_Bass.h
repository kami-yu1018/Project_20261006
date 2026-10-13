#pragma once

//	ó‘ÔŠî’êƒNƒ‰ƒX
class InGameState
{
public:
	virtual ~InGameState() = default;
	virtual void OnEnter() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnExit() = 0;
};