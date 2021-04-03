#include <iostream>
#include <windows.h>
#include "Miner.h"
#include "MinerWife.h"
#include "EntityManager.h"
using namespace std;

int main()
{
	
	srand(time(NULL));
	int maxTurn = 30;
	Miner* miner = new Miner("Bob", 0);
	MinerWife* elsa = new MinerWife("Elsa", 1);
	EntityMgr->RegisterEntity(miner);
	EntityMgr->RegisterEntity(elsa);
	for (int i = 1; i <= maxTurn; i++)
	{
		if (i % 5 == 0)system("cls");
		miner->Update();
		Sleep(1000);
	}
}