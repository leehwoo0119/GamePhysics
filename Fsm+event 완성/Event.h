#ifndef __EVENT_H_
#define __EVENT_H_

class Player;

enum EventType
{
	ET_Invalid = -1,
	ET_Machine_Power_Up,
	ET_Machine_Power_Down,
	ET_Purchase_Goods_Up,
	ET_Size
};

enum EntityType
{
	NT_Invalid = -1,
	NT_Player,
	NT_Merchant,
	NT_FactoryMachine,
	NT_Size
};


class Event
{
public:
	int etType;
	int ntType;
	int sender;
	int receiver;

public:
	Event()
	{
		etType = EventType::ET_Invalid;
		ntType = EntityType::NT_Invalid;
		sender = -1;
		receiver = -1;
	}
	Event(int src_sender, int src_receiver, int src_event)
	{
		sender = src_sender;
		receiver = src_receiver;
		etType = src_event;
	}
	virtual ~Event(){}
};

#endif
