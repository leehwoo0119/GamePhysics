#include <iostream>
#include "EventDispatcher.h"
#include "BaseGameEntity.h"
#include "EntityManager.h"
#include "Event.h"

void EventDispatcher::Event_Dispatcher(int src_sender, int src_receiver, int src_event)
{
	BaseGameEntity* pSender = EntityManager::Instance()->GetEntityFromID(src_sender);
	BaseGameEntity* pReceiver = EntityManager::Instance()->GetEntityFromID(src_receiver);
	if (pReceiver == NULL)
	{
		std::cout << "Receiver Null Error";
		return;
	}
	Event send_event(src_sender, src_receiver, src_event);
	sendEvent(pReceiver, send_event);
}

void EventDispatcher::sendEvent(BaseGameEntity* pReceiver, const Event& send_event)
{
	pReceiver->HandleEvent(send_event);
}



//void EventDispatcher::broadcastEvent(Event& send_event)
//{
//}
