#pragma once
#include <set>
#include <iostream>
using namespace std;

class BaseGameEntity;
#define Dispatch MessageDispatcher::Instance()
enum message_type
{
	Msg_Bathroom,
	Msg_WantTissue
};
struct Telegram
{
	int Sender;
	int Receiver;
	int Msg;
	Telegram() :
		Sender(-1),
		Receiver(-1),
		Msg(-1)
	{}
	Telegram(
		int    sender, int    receiver, int    msg) :		
		Sender(sender),
		Receiver(receiver),
		Msg(msg)
	{}
};

class MessageDispatcher
{
private:
	void Discharge(BaseGameEntity* pReceiver, const Telegram& msg);

	MessageDispatcher() {}

	MessageDispatcher(const MessageDispatcher&);
public:
	static MessageDispatcher* Instance();
	void Dispatch_Message(
		int    sender,
		int    receiver,
		int    msg);
};

