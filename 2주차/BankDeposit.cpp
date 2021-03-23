#include "BankDeposit.h"

void BankDeposit::Enter()
{	
	cout << endl << "은행에 도착" << endl;
	Excute();
}
void BankDeposit::Excute()
{
	int input = 0;
	cout << "금덩이가 목표치 이상인가?.(1: Yes, 2: No)" << endl;
	cout << "입력: ";
	cin >> input;
	if (input == 1)
	{
		cout << "집에서 휴식하기" << endl;
		Exit(1);	
	}
}
void BankDeposit::Exit(const int type)
{
	if(type==1)	minorstate = new HomeRest;
	ChangeState(minorstate);
}