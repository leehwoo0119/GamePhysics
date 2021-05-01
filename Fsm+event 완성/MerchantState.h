#ifndef __MERCHANTSTATE_H_
#define __MERCHANTSTATE_H_

#include "State.h"

class Merchant;

class StoreState :public State<Merchant>
{
private:
	StoreState() {}
	virtual ~StoreState() {}

public:
	static StoreState* Instance()
	{
		static StoreState instance;
		return &instance;
	}

public:
	virtual void Enter()override;
	virtual void Execute(Merchant* player)override;
	virtual void Exit()override;
	virtual bool OnEvent(Merchant* agent, const Event& event_src)override;
};

class VendingMachineState :public State<Merchant>
{
private:
	VendingMachineState() {}
	virtual ~VendingMachineState() {}

public:
	static VendingMachineState* Instance()
	{
		static VendingMachineState instance;
		return &instance;
	}

public:
	virtual void Enter()override;
	virtual void Execute(Merchant* player)override;
	virtual void Exit()override;
	virtual bool OnEvent(Merchant* agent, const Event& event_src)override;
};
#endif
