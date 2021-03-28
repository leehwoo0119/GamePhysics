#pragma once
#include "State.h"

class Miner;
class MiningGold : public State<Miner>
{
public:

	static MiningGold* Instance();

	virtual void Enter(Miner* );
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);
private:
	MiningGold() {}
	~MiningGold() {}

};

class QuenchingThirst : public State<Miner>
{

public:
	static QuenchingThirst* Instance();

	virtual void Enter(Miner*);
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);
private:
	QuenchingThirst() {}
	~QuenchingThirst() {}

};
class BankDepositGold : public State<Miner>
{
public:
	static BankDepositGold* Instance();

	virtual void Enter(Miner*);
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);

private:
	BankDepositGold() {}
	~BankDepositGold() {}
};
class RestHome : public State<Miner>
{
public:
	static RestHome* Instance();

	virtual void Enter(Miner*);
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);

private:
	RestHome() {}
	~RestHome() {}
};
//글로벌 스테이트
class MinerGlobalState : public State<Miner>
{
public:
	static MinerGlobalState* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);

private:
	MinerGlobalState() {}
	~MinerGlobalState() {}
};
class VisitBathroom : public State<Miner>
{
public:
	static VisitBathroom* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);

	//unsigned int getPercentage(Miner* miner);
private:
	VisitBathroom() {}
	~VisitBathroom() {}
};

