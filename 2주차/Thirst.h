#pragma once
#include "MinorState.h"

class Thirst : public MinorState
{
public:
	virtual void IsGoldFull() {};
	virtual void IsGoldGoal() {};
	virtual void IsFatigueFull() {};
	virtual void IsThirstFull();
	virtual void ChangeState(MinorState* state){};
};

