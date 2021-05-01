#ifndef __FACTORYMACHINE_H_
#define __FACTORYMACHINE_H_

#include "BaseGameEntity.h"
#include "StateMachine.h"

class Event;

class FactoryMachine : public BaseGameEntity
{
private:
	StateMachine<FactoryMachine>* _sm;

public:
	FactoryMachine(int id);
	virtual ~FactoryMachine();

public:
	void Update();
	virtual bool HandleEvent(const Event& src_event);
	StateMachine<FactoryMachine>* getFSM()const
	{
		return _sm;
	}
};

#endif