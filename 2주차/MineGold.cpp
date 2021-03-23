#include "MineGold.h"

void MineGold::Enter()
{
	cout << "광산에서 금덩어리 채굴";
	Excute();
}
void MineGold::Excute()
{
	cout << "......." << endl;
	Sleep(3000);
	cout << endl;
	int input = 0;
	cout << "1. 금덩이가 가득참 2. 목마름" << endl;
	cout << "입력: ";
	cin >> input;
	if (input == 1)
	{
		cout << "은행에 금 예금하기" << endl;	
		Exit(1);
	}
	if (input == 2)
	{
		cout << "갈증을 해소하기" << endl;	
		Exit(2);
	}
}
void MineGold::Exit(const int type)
{
	if (type == 1)minorstate = new BankDeposit;
	else if(type == 2)minorstate = new Thirst;
	ChangeState(minorstate);
}
