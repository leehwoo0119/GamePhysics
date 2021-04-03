#include "MinerStates.h"
#include "Miner.h"
#include "StateMachine.h"
#include <windows.h>
#include <random>
#include "MessageDispatcher.h"
//---------------------------------------------------------------
MiningGold* MiningGold::Instance()
{
	static MiningGold instance;

	return &instance;
}


void MiningGold::Enter(Miner* miner)
{
	cout << endl << "=================================================================" << endl;
	cout << miner->GetName() << "��(��) ���꿡 �����Ͽ����ϴ�." << endl;
	cout << "=================================================================" << endl << endl;
}
void MiningGold::Execute(Miner* miner)
{
	if (miner->Getter_Thirst() >= miner->Getter_MaxThirst())
	{
		cout << "���� ���� ���� �տ� ������ �ʴ´�.... �������� ����." << endl;
		miner->GetFSM()->ChangeState(QuenchingThirst::Instance());
		return;
	}
	if (miner->Getter_Gold() < miner->Getter_MaxGold())
	{	
		miner->MiningGold(1);
		cout << "ä����.... " << "(���� �� ����: " << miner->Getter_Gold() << " / " << miner->Getter_MaxGold() << ")";
		cout << " (���� ������: " << miner->Getter_Thirst() << " / " << miner->Getter_MaxThirst() << ")";
		cout << " (���� �Ƿε�: " << miner->Getter_Fatigue() << " / " << miner->Getter_MaxFatigue() << ")" << endl;
	}
	else
	{
		cout << "�ָӴϿ� ���� �����ϴ�.... ���࿡ �����Ϸ�����." << endl;
		miner->GetFSM()->ChangeState(BankDepositGold::Instance());
		return;
	}

}
void MiningGold::Exit(Miner* miner)
{
	cout << miner->GetName() << "��(��) ���꿡�� �����ϴ�." << endl;
}
//---------------------------------------------------------------
QuenchingThirst* QuenchingThirst::Instance()
{
	static QuenchingThirst instance;

	return &instance;
}


void QuenchingThirst::Enter(Miner* miner)
{
	cout << endl << "=================================================================" << endl;
	cout << miner->GetName() << "��(��) ������ �����Ͽ����ϴ�." << endl;
	cout << "=================================================================" << endl << endl;
}
void QuenchingThirst::Execute(Miner* miner)
{
	if (miner->Getter_Thirst() == 0)
	{
		cout << "���� ����� ���̴�.... �ٽ� ���Ϸ� ����." << endl;
		miner->GetFSM()->ChangeState(MiningGold::Instance());
		return;
	}
	if (miner->Getter_Thirst() > 0)
	{
		miner->QuenchThirst(7);
		cout << "���� �ؼ���.... " << "(���� ������: " << miner->Getter_Thirst() << " / " << miner->Getter_MaxThirst() << ")" << endl;
	}
}
void QuenchingThirst::Exit(Miner* miner)
{
	cout << miner->GetName() << "��(��) �������� �����ϴ�." << endl;
}
//---------------------------------------------------------------
BankDepositGold* BankDepositGold::Instance()
{
	static BankDepositGold instance;

	return &instance;
}


void BankDepositGold::Enter(Miner* miner)
{
	cout << endl << "=================================================================" << endl;
	cout << miner->GetName() << "��(��) ���࿡ �����Ͽ����ϴ�." << endl;
	cout << "=================================================================" << endl <<endl;
}
void BankDepositGold::Execute(Miner* miner)
{
	if (miner->Getter_BankGold() < miner->Getter_MaxDepositGold())
	{
		miner->DepositGold(miner->Getter_Gold());
		cout << "������.... " << "(��ǥ ���ݾ�: " << miner->Getter_BankGold() << " / " << miner->Getter_MaxDepositGold() << ")" << endl;
		
		if (miner->Getter_BankGold() == miner->Getter_MaxDepositGold())
		{
			cout << "���� ����� ��Ҵ�.... ������ �޽��Ϸ� ����." << endl;
			miner->GetFSM()->ChangeState(RestHome::Instance());
			return;
		}		
	}
	
	cout << "���� ����� ������ ���ߴ�.... �ٽ� ���Ϸ� ����." << endl;
	miner->GetFSM()->ChangeState(MiningGold::Instance());
	return;
}
void BankDepositGold::Exit(Miner* miner)
{
	cout << miner->GetName() << "��(��) ���࿡�� �����ϴ�." << endl;
}
//---------------------------------------------------------------
RestHome* RestHome::Instance()
{
	static RestHome instance;

	return &instance;
}


void RestHome::Enter(Miner* miner)
{
	cout << endl << "=================================================================" << endl;
	cout << miner->GetName() << "��(��) ���� �����Ͽ����ϴ�." << endl;
	cout << "=================================================================" << endl <<endl;
}
void RestHome::Execute(Miner* miner)
{
	if (miner->Getter_Fatigue() > 0)
	{
		miner->RestMinusFatigue(2);
		cout << "�޽���.... " << "(���� �Ƿε�: " << miner->Getter_Fatigue() << ")" << endl;
	}	

	if (miner->Getter_Fatigue() == 0)
	{
		miner->GetFSM()->ChangeState(MiningGold::Instance());
		return;
	}
}
void RestHome::Exit(Miner* miner)
{
	cout << miner->GetName() << "��(��) ������ �����ϴ�." << endl;
}
//---------------------------------------------------------------
MinerGlobalState* MinerGlobalState::Instance()
{
	static MinerGlobalState instance;

	return &instance;
}
void MinerGlobalState::Enter(Miner* miner)
{
}
void MinerGlobalState::Execute(Miner* miner)
{
	//1~100
	int randomInt = rand() % 99 + 1;
	//cout << randomInt << endl;
	//�ݱ�
	if (miner->GetFSM()->GetnowState() == MiningGold::Instance())
	{
		//10/100
		if (randomInt >= 1 && randomInt <= 10)
		{
			cout << "ȭ����� ��������.... ���ѷ� ȭ��Ƿ� ������.(Ȯ�� 10%)" << endl;
			miner->GetFSM()->ChangeState(VisitBathroom::Instance());
		}			
		return;
	}
	//����
	if (miner->GetFSM()->GetnowState() == BankDepositGold::Instance())
	{
		//10/100
		if (randomInt >= 11 && randomInt <= 20)
		{
			cout << "ȭ����� ��������.... ���ѷ� ȭ��Ƿ� ������.(Ȯ�� 10%)" << endl;
			miner->GetFSM()->ChangeState(VisitBathroom::Instance());
		}
			
		return;
	}
	//��
	if (miner->GetFSM()->GetnowState() == RestHome::Instance())
	{
		//20/100
		if (randomInt >= 21 && randomInt <= 40)
		{
			cout << "ȭ����� ��������.... ���ѷ� ȭ��Ƿ� ������.(Ȯ�� 20%)" << endl;
			miner->GetFSM()->ChangeState(VisitBathroom::Instance());
		}
			
		return;
	}
	//����
	if (miner->GetFSM()->GetnowState() == QuenchingThirst::Instance())
	{

		//30/100
		if (randomInt >= 41 && randomInt <= 70)
		{
			cout << "ȭ����� ��������.... ���ѷ� ȭ��Ƿ� ������.(Ȯ�� 30%)" << endl;
			miner->GetFSM()->ChangeState(VisitBathroom::Instance());
		}
			
		return;
	}

}

void MinerGlobalState::Exit(Miner* miner)
{
}
//---------------------------------------------------------------
VisitBathroom* VisitBathroom::Instance()
{
	static VisitBathroom instance;

	return &instance;
}

void VisitBathroom::Enter(Miner* miner)
{
	cout << endl << "=================================================================" << endl;
	cout << miner->GetName() << "��(��) ȭ��ǿ� �����Ͽ����ϴ�." << endl;
	cout << "=================================================================" << endl << endl;
}

void VisitBathroom::Execute(Miner* miner)
{
	cout << miner->GetName()<<": ������ �ʿ���." << endl;
	Dispatch->Dispatch_Message(miner->ID(), 1, Msg_WantTissue);
	//�����ص� ��������
	miner->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(Miner* miner)
{
	Sleep(1000);
	cout << miner->GetName() << "��(��) ȭ��ǿ��� �����ϴ�." << endl;
}





