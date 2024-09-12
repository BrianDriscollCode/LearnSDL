
#include "CollisionBox.h"

// Utilities

#include "../Engine/Utilities/Enum/BoxCollision.h"

CollisionBox::CollisionBox(float sizeX, float sizeY)
{
	sizeX = sizeX;
	sizeY = sizeY;

	collisionSizeX = (sizeX / 5.0f) + 0.01f;
	collisionSizeY = (sizeY / 5.0f) + 0.01f;
}



