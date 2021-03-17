#include "Agent.h"


void Agent::EvadeEnemy()
{
	isSafe = false; isThreatened = false; isStrongerThanEnemy = false; isWeakerThanEnemy = false;
	int state = 0;
	cout << endl << "Runaway 상태" << endl;
	cout << "도망갑니다." << endl;

	cout << "safe : 1" << endl << "Threatened : 2" << endl
		<< "종료: 0" << endl;
	cout << "입력: ";
		cin >> state;

		if (state == 1)isSafe = true;
		else if (state == 2)isThreatened = true;
		else if (state == 0)isOff = true;
}

void Agent::FollowPatrolPath()
{
	cout << endl << "state_Patrol 상태" << endl;
	int state = 0;
	cout << "StrongerThanEnemy: 1" << endl
		<< "WeakerThanEnemy: 2" << endl;

	cout << "입력: ";
	cin >> state;
	if (state == 1)isStrongerThanEnemy = true;
	else if (state == 2)isWeakerThanEnemy = true;
	
}


void Agent::BashEnemyOverHead()
{
	cout << endl << "BashEnemyOverHead" << endl;
}


void Agent::ChangeState(int state)
{
	UpdateState(state);
}

void Agent::UpdateState(int CurrentState)
{
	switch (CurrentState)
	{
	case state_RunAway:
		EvadeEnemy();
		if (!Safe() && !isOff)
		{
			ChangeState(state_Patrol);
		}
		break;

	case state_Patrol:
		FollowPatrolPath();

		if (Threatened())
		{
			if (StrongerThanEnemy())
			{
				ChangeState(state_Attack);
			}
			else
			{
				ChangeState(state_RunAway);
			}
		}
		break;

	case state_Attack:
		if (WeakerThanEnemy())
		{
			ChangeState(state_RunAway);
		}
		else
		{
			BashEnemyOverHead();
		}
		break;
	}//end switch
}