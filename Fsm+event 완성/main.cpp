#include <iostream>
#include <Windows.h>
#include <time.h>

#include "Player.h"
#include "Merchant.h"
#include "FactoryMachine.h"
#include "EntityManager.h"

int main()
{

	srand(time(NULL));
	Player* player1 = new Player(0);
	Merchant* merchant1 = new Merchant(1);
	FactoryMachine* machine1 = new FactoryMachine(2);
	EntityManager::Instance()->RegisterEntity(player1);
	EntityManager::Instance()->RegisterEntity(merchant1);
	EntityManager::Instance()->RegisterEntity(machine1);
	while (1)
	{
		std::cout << "=================================" << std::endl;
		player1->Update();
		merchant1->Update();
		machine1->Update();
		std::cout << "=================================" << std::endl;
		Sleep(1000);
	}
	delete player1; player1 = nullptr;
	delete merchant1; merchant1 = nullptr;
	delete machine1; machine1 = nullptr;
	return 0;
}