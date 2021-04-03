#pragma once
#include "MessageDispatcher.h"
class BaseGameEntity
{
private:
	int m_ID;
	static int  m_iNextValidID;
	void SetID(int);

public:

	BaseGameEntity(int id)
	{
		SetID(id);
	}
	virtual ~BaseGameEntity() {}
	virtual void  Update() = 0;
	virtual bool  HandleMessage(const Telegram& msg) = 0;
	int ID()const { return m_ID; }
};

