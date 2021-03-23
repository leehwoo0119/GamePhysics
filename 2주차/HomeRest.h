#pragma once
#include "MinorState.h"

class HomeRest : public MinorState
{
public:
	virtual void Enter();
	virtual void Excute();
	virtual void Exit(const int) {};
	virtual void ChangeState(MinorState* state){};
};

