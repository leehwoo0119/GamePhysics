#include <iostream>
#include <windows.h>
#include "Miner.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int maxTurn = 20;
	Miner miner("Bob");
	for (int i = 1; i <= maxTurn; i++)
	{
		miner.Update();
		Sleep(1000);
	}
}