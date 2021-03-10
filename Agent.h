#pragma once

#include <iostream>
using namespace std;

enum StateType { state_RunAway, state_Patrol, state_Attack };
class Agent
{
public:
	void UpdateState(int);
	bool isOff = false;
private:
	bool isSafe = false;
	bool isThreatened = false;
	bool isStrongerThanEnemy = false;
	bool isWeakerThanEnemy = false;
	
	void EvadeEnemy();
	void FollowPatrolPath();
	void BashEnemyOverHead();
	void ChangeState(int);
	bool Safe()
	{
		if (isSafe)return true;
		return false;
	};
	bool Threatened()
	{
		if (isThreatened)return true;
		return false;
	};
	bool WeakerThanEnemy()
	{
		if (isWeakerThanEnemy)return true;
		return false;
	};
	
	bool StrongerThanEnemy()
	{
		if (isStrongerThanEnemy)return true;
		return false;
	};
	
};

