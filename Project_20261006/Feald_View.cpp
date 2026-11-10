#include"Feald_View.h"
#include<iostream>

void FealdView::DrawMap(const char* map[], int mapW, int mapH, int playerX, int playerY)
{
	std::system("cls");
	for (int y = 0; y < mapH; ++y)
	{
		for (int x = 0; x < mapW; ++x)
		{
			//	プレイヤーの位置に記号を表示
			if (x == playerX && y == playerY)
			{
				std::cout << 'P';
			}
			else
			{
				std::cout << map[y][x];
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	std::cout << "移動　Ｗ：上　Ａ：左　Ｓ：下　Ｄ：右\n";
	std::cout << "G：ゴール\n";
}