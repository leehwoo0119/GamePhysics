#include <iostream>
#include "MerchantState.h"
#include "Merchant.h"
#include "Event.h"
using namespace std;

//StoreState
void StoreState::Enter()
{
    cout << "������ ������ ���� ���ϴ�." << endl;
}

void StoreState::Execute(Merchant* player)
{
    cout << endl << "���� ����: ����" << endl << endl;
    int rand_val = rand() % 99 + 1;

    if (rand_val >= 1 && rand_val <= 30)
    {
        cout << "������ ����մϴ�.(30%)" << endl;
        player->getFSM()->ChangeState(VendingMachineState::Instance());
    }
}

void StoreState::Exit()
{
    cout << "������ ������ ���� �ݽ��ϴ�." << endl;
}

bool StoreState::OnEvent(Merchant* agent, const Event& event_src)
{
    switch (event_src.etType)
    {
    case ET_Purchase_Goods_Up:
        cout << "������ ������ �Ǹ��մϴ�." << endl;
        break;
    default:
        break;
    }
    return false;
}

//VendingMachineState
void VendingMachineState::Enter()
{
    cout << "������ ����Ͽ� ���Ǳ��� ������ �����ϴ�." << endl;
}

void VendingMachineState::Execute(Merchant* player)
{
    cout << endl << "���� ����: ���Ǳ�" << endl << endl;
    int rand_val = rand() % 99 + 1;

    if (rand_val >= 1 && rand_val <= 30)
    {
        cout << "������ ����մϴ�.(30%)" << endl;
        player->getFSM()->ChangeState(StoreState::Instance());
    }
}

void VendingMachineState::Exit()
{
    cout << "������ ����Ͽ� ���Ǳ��� ������ �����ϴ�." << endl;
}

bool VendingMachineState::OnEvent(Merchant* agent, const Event& event_src)
{
    switch (event_src.etType)
    {
    case ET_Purchase_Goods_Up:
        cout << "���ǱⰡ ������ �Ǹ��մϴ�." << endl;
        break;
    default:
        break;
    }
    return false;
}
