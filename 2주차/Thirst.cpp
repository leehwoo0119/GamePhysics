#include "Thirst.h"

void Thirst::Enter()
{
	cout << endl << "목을 축임";
	Excute();
}
void Thirst::Excute()
{
	cout << "......." << endl;
	Sleep(3000);
	cout << endl;
	cout << "더이상 목이 마르지 않다." << endl;
}