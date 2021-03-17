#pragma once
#include "MinorState.h"
#include "HomeRest.h"
class BankDeposit: public MinorState
{
public:
	virtual void IsGoldFull() {};
	virtual void IsGoldGoal();
	virtual void IsFatigueFull() {};
	virtual void IsThirstFull() {};
	virtual void ChangeState(MinorState* state)
	{
		state->IsFatigueFull();
		delete state;
	};
};

