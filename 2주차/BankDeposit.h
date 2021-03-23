#pragma once
#include "MinorState.h"
#include "HomeRest.h"
class BankDeposit: public MinorState
{
public:
	virtual void Enter();
	virtual void Excute();
	virtual void Exit(const int);
	virtual void ChangeState(MinorState* state)
	{
		state->Enter();
		delete state;
	};
};

