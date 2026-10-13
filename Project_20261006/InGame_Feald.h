#pragma once
#include"InGame_Bass.h"

class Feald:public InGameState
{
public:
	Feald();
	~Feald();
	
	void OnEnter();
	void OnUpdate();
	void OnExit();

};

Feald::Feald()
{
}

Feald::~Feald()
{
}