#include "EntityManager.h"

EntityManager::EntityManager()
	: debugOutput(true)
{

}

BoxCollision EntityManager::CalculateDirectionalCollisions(int uniqueId, bool x, bool y)
{
	float collisionRange = .20f;

	// Gets the entity that called this function
	// For now, no other functions should insert an uniqueID of an entity which itself isn't
	Entity* entity = GetEntity(uniqueId); 

	// Loop through all registered entities
	for (auto it = allEntitiesUnderId.begin(); it != allEntitiesUnderId.end(); it++)
	{

		Entity* entityComparator = it->second; // gets the entity
		int entityComparatorId = it->first; // gets the uniqeID

		if (x && y)
		{
			debugOutput.outputRedText("ERROR::EntityManager::X and Y Flags Both True::Choose One");
		}

		// Does not compare to self via UniqueID
		if (uniqueId != entityComparatorId)
		{
			// Calculate distance between objects
			float distanceX = std::abs(entity->currentPosition.x - entityComparator->currentPosition.x);
			float distanceY = std::abs(entity->currentPosition.y - entityComparator->currentPosition.y);
			
			// if x and y axis are colliding
			if (distanceX < collisionRange && distanceY < collisionRange)
			{
				// Determine the collision side

				// With x bool true
				if (distanceX > distanceY && x)
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

				// with y bool true
				if (distanceY > distanceX && y)
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



