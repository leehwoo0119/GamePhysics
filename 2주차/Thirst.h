#pragma once
#include "MinorState.h"

class Thirst : public MinorState
{
public:
	virtual void Enter();
	virtual void Excute();
	virtual void Exit(const int) {};
	virtual void ChangeState(MinorState* state){};
};

