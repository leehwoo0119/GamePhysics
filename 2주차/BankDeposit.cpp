#include "BankDeposit.h"

void BankDeposit::IsGoldGoal()
{
	int input = 0;
	cout << "=============================================" << endl << endl;
	cout << "�ݵ��̰� ��ǥġ �̻��ΰ�?.(1: Yes, 2: No)" << endl;
	cout << "�Է�: ";
	cin >> input;
	if (input == 1)
	{
		cout << "=============================================" << endl;
		cout << "������ �޽��ϱ�" << endl;
		minorstate = new HomeRest;
		ChangeState(minorstate);
	}
}
