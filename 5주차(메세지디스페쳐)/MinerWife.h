#pragma once

#include "Miner.h"
#include "MinerWifeState.h"
#include "BaseGameEntity.h"
class MinerWife : public BaseGameEntity
{
public:
	MinerWife(string name, int id):BaseGameEntity(id) {
		Name = "Miner's Wife " + name;
		m_pStateMachine = new StateMachine<MinerWife>(this);
		m_pStateMachine->SetnowState(idle::Instance());
		//m_pStateMachine->SetGlobalState(MinerGlobalState::Instance());
	}
	~MinerWife() { delete m_pStateMachine; }

	StateMachine<MinerWife>* GetFSM()const { return m_pStateMachine; }
	virtual bool  HandleMessage(const Telegram& msg);
	void Update();
	string GetName() { return Name; }
private:
	StateMachine<MinerWife>* m_pStateMachine;

	string Name;
};

