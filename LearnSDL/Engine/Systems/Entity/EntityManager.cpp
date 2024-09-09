#include "EntityManager.h"
#include "../Engine/Systems/Entity/Entity.h"

EntityManager::EntityManager()
{

}

void EntityManager::RegisterEntity(EntityType type, int uniqueId, Entity* entity)
{
	allEntitiesUnderType[type].push_back(entity);
	allEntitiesUnderId[uniqueId].push_back(entity);
}

int EntityManager::CreateEntity(glm::vec3 position)
{
	Entity* newEntity = new Entity(position);
	uniqueId++;
	RegisterEntity(std::string("Enemy"), uniqueId, newEntity);
	return uniqueId;
}

Entity* EntityManager::GetEntity(int uniqueId)
{
	auto it = allEntitiesUnderId.find(uniqueId);
	if (it != allEntitiesUnderId.end() && !it->second.empty())
	{
		return it->second.front(); // Return the first entity in the vector
	}
	return nullptr; 
}

