#include "BankDeposit.h"

void BankDeposit::IsGoldGoal()
{
	int input = 0;
	cout << "=============================================" << endl << endl;
	cout << "금덩이가 목표치 이상인가?.(1: Yes, 2: No)" << endl;
	cout << "입력: ";
	cin >> input;
	if (input == 1)
	{
		cout << "=============================================" << endl;
		cout << "집에서 휴식하기" << endl;
		minorstate = new HomeRest;
		ChangeState(minorstate);
	}
}
