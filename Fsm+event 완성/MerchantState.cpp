#include <iostream>
#include "MerchantState.h"
#include "Merchant.h"
#include "Event.h"
using namespace std;

//StoreState
void StoreState::Enter()
{
    cout << "상인이 가게의 문을 엽니다." << endl;
}

void StoreState::Execute(Merchant* player)
{
    cout << endl << "상인 상태: 상점" << endl << endl;
    int rand_val = rand() % 99 + 1;

    if (rand_val >= 1 && rand_val <= 30)
    {
        cout << "상인이 퇴근합니다.(30%)" << endl;
        player->getFSM()->ChangeState(VendingMachineState::Instance());
    }
}

void StoreState::Exit()
{
    cout << "상인이 가게의 문을 닫습니다." << endl;
}

bool StoreState::OnEvent(Merchant* agent, const Event& event_src)
{
    switch (event_src.etType)
    {
    case ET_Purchase_Goods_Up:
        cout << "상인이 물건을 판매합니다." << endl;
        break;
    default:
        break;
    }
    return false;
}

//VendingMachineState
void VendingMachineState::Enter()
{
    cout << "상인이 퇴근하여 자판기의 전원이 켜집니다." << endl;
}

void VendingMachineState::Execute(Merchant* player)
{
    cout << endl << "상인 상태: 자판기" << endl << endl;
    int rand_val = rand() % 99 + 1;

    if (rand_val >= 1 && rand_val <= 30)
    {
        cout << "상인이 출근합니다.(30%)" << endl;
        player->getFSM()->ChangeState(StoreState::Instance());
    }
}

void VendingMachineState::Exit()
{
    cout << "상인이 출근하여 자판기의 전원이 꺼집니다." << endl;
}

bool VendingMachineState::OnEvent(Merchant* agent, const Event& event_src)
{
    switch (event_src.etType)
    {
    case ET_Purchase_Goods_Up:
        cout << "자판기가 물건을 판매합니다." << endl;
        break;
    default:
        break;
    }
    return false;
}
