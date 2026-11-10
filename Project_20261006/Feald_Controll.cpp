#include"Feald_Controll.h"


#include<iostream>
#include<conio.h>
#include<cctype>
#include<cstdlib>

void FealdControll::Init()
{
	int playerX = model.GetPlayerX();
	int playerY = model.GetPlayerY();
	view.DrawMap(MAP, MAP_W, MAP_H, playerX, playerY);
}

void FealdControll::Update()
{
	//	“ü—Í‚³‚ê‚½ƒL[
	int key = std::tolower(_getch());

	//	ˆÚ“®—Ê
	int dx = 0;
	int dy = 0;

	switch (key)
	{
	case'w':
		dy--;
		break;
	case'a':
		dx--;
		break;
	case's':
		dy++;
		break;
	case'd':
		dx++;
		break;
	default:
		return;
	}

	//	Model‚ÉˆÚ“®‚ğˆË—Š
	if (model.Move(dx, dy))
	{
		int playerX = model.GetPlayerX();
		int playerY = model.GetPlayerY();
		//	View‚É•`‰æ‚ğˆË—Š
		view.DrawMap(MAP, MAP_W, MAP_H, playerX, playerY);
		if (model.CheckEncounter())
			moveBattle = true;
	}

	if (model.IsGoal())
	{
		Goal = true;
	}
}

