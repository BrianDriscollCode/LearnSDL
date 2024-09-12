#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

// Engine
#include "../Engine/Systems/Entity/Entity.h"

// Utilities
#include "../Engine/Utilities/Enum/BoxCollision.h"

class CollisionBox
{
public:
	CollisionBox(float sizeX, float sizeY);

	float sizeX;
	float sizeY;
	float collisionSizeX;
	float collisionSizeY;

	BoxCollision CalculateDirectionalCollisionX;
	BoxCollision CalculateDirectionalCollisionY;
};

#endif