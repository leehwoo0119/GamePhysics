#ifndef __MERCHANT_H_
#define __MERCHANT_H_

#include "BaseGameEntity.h"
#include "StateMachine.h"

class Event;

class Merchant : public BaseGameEntity
{
private:
	StateMachine<Merchant>* _sm;

public:
	Merchant(int id);
	virtual ~Merchant();

public:
	void Update();
	virtual bool HandleEvent(const Event& src_event);
	StateMachine<Merchant>* getFSM()const
	{
		return _sm;
	}
};

#endif

