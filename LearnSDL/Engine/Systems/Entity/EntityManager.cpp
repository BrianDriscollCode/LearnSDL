#include "EntityManager.h"

EntityManager::EntityManager()
{

}

BoxCollision EntityManager::CalculateDirectionalCollisions(int uniqueId)
{
	float collisionRange = .20f;
	Entity* entity = GetEntity(uniqueId);

	for (auto it = allEntitiesUnderId.begin(); it != allEntitiesUnderId.end(); it++)
	{
		Entity* entityComparator = it->second;
		int entityComparatorId = it->first;

		if (uniqueId != entityComparatorId)
		{
			float distanceX = std::abs(entity->currentPosition.x - entityComparator->currentPosition.x);
			float distanceY = std::abs(entity->currentPosition.y - entityComparator->currentPosition.y);
			
			if (distanceX < collisionRange && distanceY < collisionRange)
			{
				// Determine the collision side
				if (distanceX > distanceY)
				{
					if (entity->currentPosition.x < entityComparator->currentPosition.x)
					{
						printf("Collision on the right side\n");
						return RIGHT_COL;
					}
					else
					{
						printf("Collision on the left side\n");
						return LEFT_COL;
					}
				}

				if (distanceY > distanceX)
				{
					if (entity->currentPosition.y > entityComparator->currentPosition.y)
					{
						printf("Collision on the bottom side\n");
						return BOTTOM_COL;
					}
					else
					{
						printf("Collision on the top side\n");
						return TOP_COL;
					}
				}
				
				//printf("Current X collision range: %f\n", distanceX);
				//printf("Current Y collision range: %f\n", distanceY);
				return NO_COL;
			}
		}
	}
	return NO_COL;
}

void EntityManager::RegisterEntity(EntityType type, int uniqueId, Entity* entity)
{
	allEntitiesUnderType[type].push_back(entity);
	allEntitiesUnderId[uniqueId] = entity;
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
	if (it != allEntitiesUnderId.end())
	{
		return it->second; // Return the first entity in the vector
	}
	return nullptr; 
}



