#ifndef __EVENTDISPATCHER_H_
#define __EVENTDISPATCHER_H_

class Event;
class BaseGameEntity;

class EventDispatcher
{
public:
	static EventDispatcher* Instance()
	{
		static EventDispatcher instance;
		return &instance;
	}

public:
	void Event_Dispatcher(int sender, int receiver, int src_event);
	void sendEvent(BaseGameEntity* pReceiver, const Event& send_event);
	
};

#endif