#include "MinerWife.h"

bool MinerWife::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

void MinerWife::Update()
{
	m_pStateMachine->Update();
}
