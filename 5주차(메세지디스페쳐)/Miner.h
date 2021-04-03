#pragma once
#include <iostream>
#include "StateMachine.h"
#include "MinerStates.h"
#include "BaseGameEntity.h"
using namespace std;


class Miner : public BaseGameEntity
{

public:
	Miner(string name, int id):BaseGameEntity(id) {
		Name = "Miner " + name;
		m_pStateMachine = new StateMachine<Miner>(this);
		m_pStateMachine->SetnowState(RestHome::Instance());
		m_pStateMachine->SetGlobalState(MinerGlobalState::Instance());
	}
	~Miner() { delete m_pStateMachine; }

	//변수들 외부에서 접근
	string GetName() { return Name; }
	int Getter_Thirst() { return Thirst; };
	int Getter_MaxThirst() { return MaxThirst; };
	int Getter_Gold() { return Gold; };
	int Getter_MaxGold() { return MaxGold; };
	int Getter_Fatigue() { return Fatigue; };
	int Getter_MaxFatigue() { return MaxFatigue; };
	int Getter_BankGold() { return BankGold; };
	int Getter_MaxDepositGold() { return MaxDepositGold; };

	void Update();

	void MiningGold(const int);
	void RestMinusFatigue(const int);
	void QuenchThirst(const int);
	void DepositGold(const int);
	StateMachine<Miner>* GetFSM()const { return m_pStateMachine; }
	virtual bool HandleMessage(const Telegram& msg);

private:
	StateMachine<Miner>* m_pStateMachine;

	string Name;
	int Gold;
	int Thirst;
	int Fatigue;
	int BankGold;

	int MaxGold = 5;
	int MaxThirst = 21;
	int MaxFatigue = 10;
	int MaxDepositGold = 10;

};
