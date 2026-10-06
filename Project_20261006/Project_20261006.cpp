#include <iostream>
#include"GameManager.h"
#include"State_Startup.h"

GameManager manager(std::make_unique<State_Startup>());

int main()
{
	while (1)
	{
		manager.Update(1.0f);
	}
}

