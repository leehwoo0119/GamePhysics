#include <iostream>
#include "PlayerState.h"
#include "Player.h"
#include "Event.h"
#include "EventDispatcher.h"

using namespace std;

//HomeState
void HomeState::Enter()
{
	cout << "플레이어가 집의 문을 엽니다." << endl;
}

void HomeState::Execute(Player* player)
{
	cout << endl << "플레이어 상태: 집" << endl << endl;
	int rand_val = rand() % 99 + 1;

	if (rand_val >= 1 && rand_val <= 30)
	{
		cout << "플레이어가 공장으로 출근합니다.(30%)" << endl << endl;
		player->getFSM()->ChangeState(FactoryState::Instance());
	}
}

void HomeState::Exit()
{
	cout << "플레이어가 집의 문을 닫습니다." << endl;
}

bool HomeState::OnEvent(Player* agent, const Event& event_src)
{
	return false;
}

//FactoryState
void FactoryState::Enter()
{
	cout << "플레이어가 공장의 문을 엽니다." << endl;
}

void FactoryState::Execute(Player* player)
{
	cout << endl << "플레이어 상태: 공장" << endl << endl;
	int rand_val = rand() % 99 + 1;
	
	if (!isFactoryMachine_PowerOn)
	{
		if (rand_val >= 31 && rand_val <= 100)
		{
			cout << "플레이어가 공장의 장비를 동작 시킵니다.(70%)" << endl;
			EventDispatcher::Instance()->
				Event_Dispatcher(player->ID(), NT_FactoryMachine, ET_Machine_Power_Up);
			isFactoryMachine_PowerOn = true;
		}		
	}	
	else
	{
		if (rand_val >= 31 && rand_val <= 50)
		{
			cout << "플레이어가 공장의 장비를 멈춥니다.(20%)" << endl;
			EventDispatcher::Instance()->
				Event_Dispatcher(player->ID(), NT_FactoryMachine, ET_Machine_Power_Down);
			isFactoryMachine_PowerOn = false;
		}
	}
	if (rand_val >= 1 && rand_val <= 30)
	{
		cout << "플레이어가 공장의 문을 닫습니다.(30%)" << endl;
		player->getFSM()->ChangeState(HomeState::Instance());
	}

}
void FactoryState::Exit()
{
	cout << "플레이어가 공장의 문을 닫습니다." << endl;
}

bool FactoryState::OnEvent(Player* agent, const Event& event_src)
{
	return false;
}

//GlobalState

void GlobalState::Enter()
{
}

void GlobalState::Execute(Player* player)
{
	int rand_val = rand() % 99 + 1;

	if (rand_val >= 1 && rand_val <= 30)
	{
		cout << "플레이어가 상점에서 물건을 구매합니다.(30%)" << endl;
		EventDispatcher::Instance()->
			Event_Dispatcher(player->ID(), NT_Merchant, ET_Purchase_Goods_Up);
	}
}
void GlobalState::Exit()
{
}

bool GlobalState::OnEvent(Player* agent, const Event& event_src)
{
	return false;
}