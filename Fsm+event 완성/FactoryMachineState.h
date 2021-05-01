#ifndef __FACTORYMACHINESTATE_H_
#define __FACTORYMACHINESTATE_H_

#include "State.h"

class FactoryMachine;

class FactoryMachineState :public State<FactoryMachine>
{
private:
	bool isFactoryMachine_PowerOn = false;

private:
	FactoryMachineState() {}
	virtual ~FactoryMachineState() {}

public:
	static FactoryMachineState* Instance()
	{
		static FactoryMachineState instance;
		return &instance;
	}

public:
	virtual void Enter()override;
	virtual void Execute(FactoryMachine* player)override;
	virtual void Exit()override;
	virtual bool OnEvent(FactoryMachine* agent, const Event& event_src)override;
};
#endif