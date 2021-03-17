#pragma once
#include "MinorState.h"
#include "BankDeposit.h"
#include "Thirst.h"

class MineGold : public MinorState
{
public:
	virtual void IsGoldFull();
	virtual void IsGoldGoal() {};
	virtual void IsFatigueFull() {};
	virtual void IsThirstFull() {};
	virtual void ChangeState(MinorState* state)
	{
		state->IsGoldGoal();
		state->IsThirstFull();
		delete state;
	};
};

