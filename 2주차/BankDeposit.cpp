#include "BankDeposit.h"

void BankDeposit::Enter()
{	
	cout << endl << "���࿡ ����" << endl;
	Excute();
}
void BankDeposit::Excute()
{
	int input = 0;
	cout << "�ݵ��̰� ��ǥġ �̻��ΰ�?.(1: Yes, 2: No)" << endl;
	cout << "�Է�: ";
	cin >> input;
	if (input == 1)
	{
		cout << "������ �޽��ϱ�" << endl;
		Exit(1);	
	}
}
void BankDeposit::Exit(const int type)
{
	if(type==1)	minorstate = new HomeRest;
	ChangeState(minorstate);
}