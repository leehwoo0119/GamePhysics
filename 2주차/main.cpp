#include "MinorState.h"
#include "MineGold.h"

int main()
{
	MinorState* minorstate = new MineGold;
	for (int i = 1; i <= 20; i++)
	{
		cout << "=============================================" << endl;
		cout << "\n" << "ÇöÀç ÅÏ: " << i <<" / 20"<< endl;
		minorstate->Enter();
	}
	delete minorstate;
	return 0;
}