#include "MineGold.h"

void MineGold::Enter()
{
	cout << "���꿡�� �ݵ�� ä��";
	Excute();
}
void MineGold::Excute()
{
	cout << "......." << endl;
	Sleep(3000);
	cout << endl;
	int input = 0;
	cout << "1. �ݵ��̰� ������ 2. �񸶸�" << endl;
	cout << "�Է�: ";
	cin >> input;
	if (input == 1)
	{
		cout << "���࿡ �� �����ϱ�" << endl;	
		Exit(1);
	}
	if (input == 2)
	{
		cout << "������ �ؼ��ϱ�" << endl;	
		Exit(2);
	}
}
void MineGold::Exit(const int type)
{
	if (type == 1)minorstate = new BankDeposit;
	else if(type == 2)minorstate = new Thirst;
	ChangeState(minorstate);
}
