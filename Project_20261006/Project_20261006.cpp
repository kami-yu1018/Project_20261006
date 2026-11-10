#include <iostream>
#include"GameManager.h"
#include"State_Startup.h"
#include<cstdlib>
#include<ctime>

GameManager manager(std::make_unique<State_Startup>());

int main()
{
	srand((unsigned int)time(NULL));

	while (1)
	{
		manager.Update(1.0f);
	}
}

