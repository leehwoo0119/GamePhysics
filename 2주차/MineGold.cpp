#include "MineGold.h"

void MineGold::IsGoldFull()
{
	int input = 0;
	cout << "=============================================" << endl;
	cout << "광산에서 금덩어리 채굴" << endl;
	cout << "=============================================" << endl << endl;
	cout << "1. 금덩이가 가득참 2. 목마름" << endl;
	cout << "입력: ";
	cin >> input;
	if (input == 1)
	{
		cout << "=============================================" << endl;
		cout << "은행에 금 예금하기" << endl;
		minorstate = new BankDeposit;
		ChangeState(minorstate);
	}
	if (input == 2)
	{
		cout << "=============================================" << endl;
		cout << "갈증을 해소하기" << endl;
		minorstate = new Thirst;
		ChangeState(minorstate);
	}
}

