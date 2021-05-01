#ifndef __ENITITYMANAGER_H_
#define __ENITITYMANAGER_H_
#include <map>

class BaseGameEntity;

class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*>EntityMap;
	EntityMap m_EntityMap;

private:
	EntityManager() {};
	virtual ~EntityManager() {};

public:
	static EntityManager* Instance()
	{
		static EntityManager instance;
		return &instance;
	}

public:
	void RemoveEntity(BaseGameEntity* pEntity);
	void RegisterEntity(BaseGameEntity* NewEntity);
	BaseGameEntity* GetEntityFromID(int id)const;
};

#endif
