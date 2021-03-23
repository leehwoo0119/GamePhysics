#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
class MinorState
{
	
public:
	MinorState* minorstate = 0;
	virtual void Enter() = 0;
	virtual void Excute() = 0;
	virtual void Exit(const int) = 0;
	virtual void ChangeState(MinorState* state) = 0;
};

