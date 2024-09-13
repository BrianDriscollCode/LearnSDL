
#include "CollisionBox.h"


CollisionBox::CollisionBox()
{

}

void CollisionBox::InitCollisionBox(float sizeX, float sizeY)
{
	sizeX = sizeX;
	sizeY = sizeY;

	collisionSizeX = (sizeX / 5.0f) + 0.005f;
	collisionSizeY = (sizeY / 5.0f) + 0.005f;
}

BoxCollision CollisionBox::CalculateDirectionalCollisionX(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId)
{

	for (auto it = allEntitiesUnderId->begin(); it != allEntitiesUnderId->end(); it++)
	{
		Entity* entityComparator = it->second;
		int entityComparatorId = it->first;

		if (uniqueId != entityComparatorId)
		{
			// Calculate distance between objects
			float currentDistanceX = std::round(std::abs(entity->currentPosition.x - entityComparator->currentPosition.x) * 100) / 100;
			float currentDistanceY = std::round(std::abs(entity->currentPosition.y - entityComparator->currentPosition.y) * 100) / 100;
		
			if (currentDistanceX < collisionSizeX && currentDistanceY < collisionSizeY)
			{
				
				if (currentDistanceX > currentDistanceY)
				{
					if (entity->currentPosition.x < entityComparator->currentPosition.x)
					{
						printf("CurrentXDistance: %.2f\n", currentDistanceX);
						//printf("Collision on the right side\n");
						return RIGHT_COL;
					}
					else
					{
						printf("CurrentXDistance: %.2f\n", currentDistanceX);
						//printf("Collision on the left side\n");
						return LEFT_COL;
					}
				}
			}
		}
	}

	return NO_COL;
}

BoxCollision CollisionBox::CalculateDirectionalCollisionY(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId)
{
	for (auto it = allEntitiesUnderId->begin(); it != allEntitiesUnderId->end(); it++)
	{
		Entity* entityComparator = it->second;
		int entityComparatorId = it->first;

		if (uniqueId != entityComparatorId)
		{
			// Calculate distance between objects
			float currentDistanceX = std::round(std::abs(entity->currentPosition.x - entityComparator->currentPosition.x) * 100) / 100;
			float currentDistanceY = std::round(std::abs(entity->currentPosition.y - entityComparator->currentPosition.y) * 100) / 100;

			if (currentDistanceX < collisionSizeX && currentDistanceY < collisionSizeY)
			{

				// with y bool true
				if (currentDistanceY > currentDistanceX)
				{
					if (entity->currentPosition.y > entityComparator->currentPosition.y)
					{
						//printf("Collision on the bottom side\n");
						printf("CurrentYDistance: %.2f\n", currentDistanceY);
						return BOTTOM_COL;
					}
					else
					{
						printf("CurrentYDistance: %.2f\n", currentDistanceY);
						//printf("Collision on the top side\n");
						return TOP_COL;
					}
				}
			}
		}
	}
	//printf("No Collision\n");
	return NO_COL;
}



