#include "MinorState.h"
#include "MineGold.h"

int main()
{
	MinorState* minorstate = new MineGold;
	for (int i = 1; i <= 20; i++)
	{
		cout << "=============================================" << endl;
		cout << "\n" << "���� ��: " << i <<" / 20"<< endl;
		minorstate->IsGoldFull();
	}
	delete minorstate;
	return 0;
}