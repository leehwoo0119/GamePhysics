#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "BaseGameEntity.h"
#include "StateMachine.h"

class Event;

class Player : public BaseGameEntity
{
private:
	StateMachine<Player>* _sm;

public:
	Player(int id);
	virtual ~Player();

public:
	void Update();
	virtual bool HandleEvent(const Event& src_event);
	StateMachine<Player>* getFSM()const
	{
		return _sm;
	}
};

#endif
