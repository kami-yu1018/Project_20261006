#pragma once
#include"Feald_Model.h"
#include"Feald_View.h"

class FealdControll
{
	FealdModel model;
	FealdView view;

public:
	bool moveBattle = false;
	bool Goal = false;

	void Init();
	void Update();
	void Exit();
};