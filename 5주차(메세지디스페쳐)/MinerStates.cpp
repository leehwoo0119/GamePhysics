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
	cout << miner->GetName() << "이(가) 광산에 도착하였습니다." << endl;
	cout << "=================================================================" << endl << endl;
}
void MiningGold::Execute(Miner* miner)
{
	if (miner->Getter_Thirst() >= miner->Getter_MaxThirst())
	{
		cout << "목이 말라서 일이 손에 잡히지 않는다.... 술집으로 가자." << endl;
		miner->GetFSM()->ChangeState(QuenchingThirst::Instance());
		return;
	}
	if (miner->Getter_Gold() < miner->Getter_MaxGold())
	{	
		miner->MiningGold(1);
		cout << "채광중.... " << "(현재 금 갯수: " << miner->Getter_Gold() << " / " << miner->Getter_MaxGold() << ")";
		cout << " (현재 갈증도: " << miner->Getter_Thirst() << " / " << miner->Getter_MaxThirst() << ")";
		cout << " (현재 피로도: " << miner->Getter_Fatigue() << " / " << miner->Getter_MaxFatigue() << ")" << endl;
	}
	else
	{
		cout << "주머니에 금이 가득하다.... 은행에 예금하러가자." << endl;
		miner->GetFSM()->ChangeState(BankDepositGold::Instance());
		return;
	}

}
void MiningGold::Exit(Miner* miner)
{
	cout << miner->GetName() << "이(가) 광산에서 떠납니다." << endl;
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
	cout << miner->GetName() << "이(가) 술집에 도착하였습니다." << endl;
	cout << "=================================================================" << endl << endl;
}
void QuenchingThirst::Execute(Miner* miner)
{
	if (miner->Getter_Thirst() == 0)
	{
		cout << "술을 충분히 마셨다.... 다시 일하러 가자." << endl;
		miner->GetFSM()->ChangeState(MiningGold::Instance());
		return;
	}
	if (miner->Getter_Thirst() > 0)
	{
		miner->QuenchThirst(7);
		cout << "갈증 해소중.... " << "(현재 갈증도: " << miner->Getter_Thirst() << " / " << miner->Getter_MaxThirst() << ")" << endl;
	}
}
void QuenchingThirst::Exit(Miner* miner)
{
	cout << miner->GetName() << "이(가) 술집에서 떠납니다." << endl;
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
	cout << miner->GetName() << "이(가) 은행에 도착하였습니다." << endl;
	cout << "=================================================================" << endl <<endl;
}
void BankDepositGold::Execute(Miner* miner)
{
	if (miner->Getter_BankGold() < miner->Getter_MaxDepositGold())
	{
		miner->DepositGold(miner->Getter_Gold());
		cout << "예금중.... " << "(목표 예금액: " << miner->Getter_BankGold() << " / " << miner->Getter_MaxDepositGold() << ")" << endl;
		
		if (miner->Getter_BankGold() == miner->Getter_MaxDepositGold())
		{
			cout << "금을 충분히 모았다.... 집으로 휴식하러 가자." << endl;
			miner->GetFSM()->ChangeState(RestHome::Instance());
			return;
		}		
	}
	
	cout << "금을 충분히 모으지 못했다.... 다시 일하러 가자." << endl;
	miner->GetFSM()->ChangeState(MiningGold::Instance());
	return;
}
void BankDepositGold::Exit(Miner* miner)
{
	cout << miner->GetName() << "이(가) 은행에서 떠납니다." << endl;
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
	cout << miner->GetName() << "이(가) 집에 도착하였습니다." << endl;
	cout << "=================================================================" << endl <<endl;
}
void RestHome::Execute(Miner* miner)
{
	if (miner->Getter_Fatigue() > 0)
	{
		miner->RestMinusFatigue(2);
		cout << "휴식중.... " << "(현재 피로도: " << miner->Getter_Fatigue() << ")" << endl;
	}	

	if (miner->Getter_Fatigue() == 0)
	{
		miner->GetFSM()->ChangeState(MiningGold::Instance());
		return;
	}
}
void RestHome::Exit(Miner* miner)
{
	cout << miner->GetName() << "이(가) 집에서 떠납니다." << endl;
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
	//금광
	if (miner->GetFSM()->GetnowState() == MiningGold::Instance())
	{
		//10/100
		if (randomInt >= 1 && randomInt <= 10)
		{
			cout << "화장실이 급해졌다.... 서둘러 화장실로 향하자.(확률 10%)" << endl;
			miner->GetFSM()->ChangeState(VisitBathroom::Instance());
		}			
		return;
	}
	//은행
	if (miner->GetFSM()->GetnowState() == BankDepositGold::Instance())
	{
		//10/100
		if (randomInt >= 11 && randomInt <= 20)
		{
			cout << "화장실이 급해졌다.... 서둘러 화장실로 향하자.(확률 10%)" << endl;
			miner->GetFSM()->ChangeState(VisitBathroom::Instance());
		}
			
		return;
	}
	//집
	if (miner->GetFSM()->GetnowState() == RestHome::Instance())
	{
		//20/100
		if (randomInt >= 21 && randomInt <= 40)
		{
			cout << "화장실이 급해졌다.... 서둘러 화장실로 향하자.(확률 20%)" << endl;
			miner->GetFSM()->ChangeState(VisitBathroom::Instance());
		}
			
		return;
	}
	//술집
	if (miner->GetFSM()->GetnowState() == QuenchingThirst::Instance())
	{

		//30/100
		if (randomInt >= 41 && randomInt <= 70)
		{
			cout << "화장실이 급해졌다.... 서둘러 화장실로 향하자.(확률 30%)" << endl;
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
	cout << miner->GetName() << "이(가) 화장실에 도착하였습니다." << endl;
	cout << "=================================================================" << endl << endl;
}

void VisitBathroom::Execute(Miner* miner)
{
	cout << miner->GetName()<<": 휴지가 필요해." << endl;
	Dispatch->Dispatch_Message(miner->ID(), 1, Msg_WantTissue);
	//저장해둔 이전으로
	miner->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(Miner* miner)
{
	Sleep(1000);
	cout << miner->GetName() << "이(가) 화장실에서 떠납니다." << endl;
}





