#pragma once
#include <iostream>

using namespace std;
class MinorState
{
	
public:
	MinorState* minorstate = 0;
	virtual void IsGoldFull() = 0;
	virtual void IsGoldGoal() = 0;
	virtual void IsFatigueFull() = 0;
	virtual void IsThirstFull() = 0;
	virtual void ChangeState(MinorState* state) = 0;
};

