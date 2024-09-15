#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include <unordered_map>

// Engine
#include "../Engine/Systems/Entity/Entity.h"

// Utilities
#include "../Engine/Utilities/Enum/BoxCollision.h"
#include "../Engine/Utilities/Enum/CollisionTypeSelector.h"

class CollisionBox
{
public:
	CollisionBox();

	float sizeX;
	float sizeY;
	
	CollisionTypeSelector collisionType;
	int printCounter = 0;

	void InitCollisionBox(float sizeXRef, float sizeYRef);
	BoxCollision CalculateDirectionalCollisionX(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId);
	BoxCollision CalculateDirectionalCollisionY(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId);

	bool TriggerCollision(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId);
};

#endif