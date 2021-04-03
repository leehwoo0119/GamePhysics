#include "MinerWifeState.h"
#include "MinerWife.h"
#include "MessageDispatcher.h"
idle* idle::Instance()
{
	static idle instance;

	return &instance;
}

void idle::Enter(MinerWife*)
{
}

void idle::Execute(MinerWife*)
{
}

void idle::Exit(MinerWife*)
{
}

bool idle::OnMessage(MinerWife* wife, const Telegram& msg)
{
    switch (msg.Msg)
    {
    case Msg_WantTissue:
    {
        cout << wife->GetName() << ": ÈÞÁö°¡ ´Ù ¶³¾îÁ³¾î¿ä." << endl;
       // wife->GetFSM()->ChangeState(idle::Instance());
        return true;
    }
    }
    return false;
}



