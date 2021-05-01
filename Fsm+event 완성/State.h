#ifndef __STATE_H_
#define __STATE_H_

class Event;

template<class T>
class State
{
public:
	State() {}
	virtual ~State() {}
public:

	virtual void Enter() = 0;

	virtual void Execute(T*) = 0;

	virtual void Exit() = 0;

	virtual bool OnEvent(T* agent, const Event& event_src) = 0;

};

#endif
