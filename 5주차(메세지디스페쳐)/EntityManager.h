#pragma once
#include <map>

class BaseGameEntity;
#define EntityMgr EntityManager::Instance()
class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*>EntityMap;
	EntityMap m_EntityMap;

	EntityManager() {}
	EntityManager(const EntityManager&);

public:
	static EntityManager* Instance();
	BaseGameEntity* GetEntityFromID(int id)const;
	void RemoveEntity(BaseGameEntity* pEntity);
	void RegisterEntity(BaseGameEntity* NewEntity);
};

