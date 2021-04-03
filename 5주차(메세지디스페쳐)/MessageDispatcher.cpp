#include "MessageDispatcher.h"
#include "BaseGameEntity.h"
#include "EntityManager.h"

MessageDispatcher* MessageDispatcher::Instance()
{
	static MessageDispatcher instance;

	return &instance;
}
void MessageDispatcher::Dispatch_Message(int sender, int receiver, int msg)
{
	BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);
	if (pReceiver == NULL)
	{
		cout << "\nWarning! No Receiver with ID of " << receiver << " found";

		return;
	}
	Telegram telegram(sender, receiver, msg);
	Discharge(pReceiver, telegram);
}
void MessageDispatcher::Discharge(BaseGameEntity* pReceiver, const Telegram& telegram)
{
	if (!pReceiver->HandleMessage(telegram))
	{
		std::cout << "Message not handled";

		return;
	}
}

