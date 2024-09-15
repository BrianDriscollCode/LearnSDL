#include "EntityManager.h"

EntityManager::EntityManager()
	: debugOutput(true)
{

}

// Register entity and Set UniqueId with entity and on calling object
// Example: Player Class calls "RegisterEntity" and receives uniqueID
int EntityManager::RegisterEntity(EntityType type, Entity* entity)
{
	uniqueId++;
	allEntitiesUnderType[type].push_back(entity);
	allEntitiesUnderId[uniqueId] = entity;
	return uniqueId;
}

Entity* EntityManager::GetEntity(int uniqueId)
{
	auto it = allEntitiesUnderId.find(uniqueId);
	if (it != allEntitiesUnderId.end())
	{
		return it->second; // Return the first entity in the vector
	}
	return nullptr;
}

std::unordered_map<int, Entity*>* EntityManager::GetAllEntities()
{
	return &allEntitiesUnderId;
}


