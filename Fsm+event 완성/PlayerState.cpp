#include <iostream>
#include "PlayerState.h"
#include "Player.h"
#include "Event.h"
#include "EventDispatcher.h"

using namespace std;

//HomeState
void HomeState::Enter()
{
	cout << "�÷��̾ ���� ���� ���ϴ�." << endl;
}

void HomeState::Execute(Player* player)
{
	cout << endl << "�÷��̾� ����: ��" << endl << endl;
	int rand_val = rand() % 99 + 1;

	if (rand_val >= 1 && rand_val <= 30)
	{
		cout << "�÷��̾ �������� ����մϴ�.(30%)" << endl << endl;
		player->getFSM()->ChangeState(FactoryState::Instance());
	}
}

void HomeState::Exit()
{
	cout << "�÷��̾ ���� ���� �ݽ��ϴ�." << endl;
}

bool HomeState::OnEvent(Player* agent, const Event& event_src)
{
	return false;
}

//FactoryState
void FactoryState::Enter()
{
	cout << "�÷��̾ ������ ���� ���ϴ�." << endl;
}

void FactoryState::Execute(Player* player)
{
	cout << endl << "�÷��̾� ����: ����" << endl << endl;
	int rand_val = rand() % 99 + 1;
	
	if (!isFactoryMachine_PowerOn)
	{
		if (rand_val >= 31 && rand_val <= 100)
		{
			cout << "�÷��̾ ������ ��� ���� ��ŵ�ϴ�.(70%)" << endl;
			EventDispatcher::Instance()->
				Event_Dispatcher(player->ID(), NT_FactoryMachine, ET_Machine_Power_Up);
			isFactoryMachine_PowerOn = true;
		}		
	}	
	else
	{
		if (rand_val >= 31 && rand_val <= 50)
		{
			cout << "�÷��̾ ������ ��� ����ϴ�.(20%)" << endl;
			EventDispatcher::Instance()->
				Event_Dispatcher(player->ID(), NT_FactoryMachine, ET_Machine_Power_Down);
			isFactoryMachine_PowerOn = false;
		}
	}
	if (rand_val >= 1 && rand_val <= 30)
	{
		cout << "�÷��̾ ������ ���� �ݽ��ϴ�.(30%)" << endl;
		player->getFSM()->ChangeState(HomeState::Instance());
	}

}
void FactoryState::Exit()
{
	cout << "�÷��̾ ������ ���� �ݽ��ϴ�." << endl;
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
		cout << "�÷��̾ �������� ������ �����մϴ�.(30%)" << endl;
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