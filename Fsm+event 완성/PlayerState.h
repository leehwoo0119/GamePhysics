#ifndef __PLAYERHOMESTATE_H_
#define __PLAYERHOMESTATE_H_

#include "State.h"

class Player;

class HomeState :public State<Player>
{
private:
	HomeState() {}
	virtual ~HomeState() {}

public:
	static HomeState* Instance()
	{
		static HomeState instance;
		return &instance;
	}

public:
	virtual void Enter()override;
	virtual void Execute(Player* player)override;
	virtual void Exit()override;
	virtual bool OnEvent(Player* agent, const Event& event_src)override;
};

class FactoryState :public State<Player>
{
private:
	bool isFactoryMachine_PowerOn = false;

private:
	FactoryState() {}
	virtual ~FactoryState() {}

public:
	static FactoryState* Instance()
	{
		static FactoryState instance;
		return &instance;
	}

public:
	virtual void Enter()override;
	virtual void Execute(Player* player)override;
	virtual void Exit()override;
	virtual bool OnEvent(Player* agent, const Event& event_src)override;

};

class GlobalState :public State<Player>
{
private:
	GlobalState() {}
	virtual ~GlobalState() {}

public:
	static GlobalState* Instance()
	{
		static GlobalState instance;
		return &instance;
	}

public:
	virtual void Enter()override;
	virtual void Execute(Player* player)override;
	virtual void Exit()override;
	virtual bool OnEvent(Player* agent, const Event& event_src)override;
};
#endif