#include "HomeRest.h"

void HomeRest::Enter()
{
	cout << endl << "집에 도착";
	Excute();
}
void HomeRest::Excute()
{
	cout << "......." << endl;
	Sleep(3000);
	cout << endl;
	cout << "피로가 회복되었다." << endl;
}
