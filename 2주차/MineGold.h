#pragma once
#include "MinorState.h"
#include "BankDeposit.h"
#include "Thirst.h"

class MineGold : public MinorState
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

