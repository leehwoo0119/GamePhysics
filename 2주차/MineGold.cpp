#include "MineGold.h"

void MineGold::IsGoldFull()
{
	int input = 0;
	cout << "=============================================" << endl;
	cout << "���꿡�� �ݵ�� ä��" << endl;
	cout << "=============================================" << endl << endl;
	cout << "1. �ݵ��̰� ������ 2. �񸶸�" << endl;
	cout << "�Է�: ";
	cin >> input;
	if (input == 1)
	{
		cout << "=============================================" << endl;
		cout << "���࿡ �� �����ϱ�" << endl;
		minorstate = new BankDeposit;
		ChangeState(minorstate);
	}
	if (input == 2)
	{
		cout << "=============================================" << endl;
		cout << "������ �ؼ��ϱ�" << endl;
		minorstate = new Thirst;
		ChangeState(minorstate);
	}
}

