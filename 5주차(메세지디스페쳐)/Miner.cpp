#include "Miner.h"

void Miner::Update()
{
	m_pStateMachine->Update();
}

void Miner::MiningGold(const int val)
{
	Gold += val;
	Thirst += val * 3;
	Fatigue += val;
}

void Miner::RestMinusFatigue(const int val)
{
	Fatigue -= val;
}

void Miner::QuenchThirst(const int val)
{
	Thirst -= val;
}

void Miner::DepositGold(const int val)
{
	BankGold += val;
	Gold -= val;
}

bool Miner::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

