#pragma once
#include "MinorState.h"

class HomeRest : public MinorState
{
public:
	virtual void IsGoldFull() {};
	virtual void IsGoldGoal() {};
	virtual void IsFatigueFull();
	virtual void IsThirstFull() {};
	virtual void ChangeState(MinorState* state){};
};

