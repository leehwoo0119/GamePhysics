#ifndef __BASEGAMEENTITY_H_
#define __BASEGAMEENTITY_H_

class Event;

class BaseGameEntity
{
public:
	BaseGameEntity(int id)
	{
		SetID(id);
	}
	virtual ~BaseGameEntity() {}

private:
	int m_ID;
	void SetID(int);

public:
	virtual void  Update() = 0;
	int ID()const { return m_ID; }

	virtual bool  HandleEvent(const Event& msg) = 0;
};

#endif
