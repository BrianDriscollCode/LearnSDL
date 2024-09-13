#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include <unordered_map>

// Engine
#include "../Engine/Systems/Entity/Entity.h"

// Utilities
#include "../Engine/Utilities/Enum/BoxCollision.h"

class CollisionBox
{
public:
	CollisionBox();

	float sizeX;
	float sizeY;
	float collisionSizeX;
	float collisionSizeY;

	void InitCollisionBox(float sizeX, float sizeY);
	BoxCollision CalculateDirectionalCollisionX(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId);
	BoxCollision CalculateDirectionalCollisionY(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId);
};

#endif