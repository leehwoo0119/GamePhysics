#pragma once
#include "State.h"
#include <iostream>
using namespace std;
struct Telegram;
class MinerWife;
class idle: public State<MinerWife>
{
public:

	static idle* Instance();

	virtual void Enter(MinerWife*);
	virtual void Execute(MinerWife*);
	virtual void Exit(MinerWife*);
	virtual bool OnMessage(MinerWife* wife, const Telegram& msg);
private:
	idle() {}
	~idle() {}
};

