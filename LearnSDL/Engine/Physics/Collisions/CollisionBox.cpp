#include "CollisionBox.h"

CollisionBox::CollisionBox() {}

void CollisionBox::InitCollisionBox(glm::vec2 size, CollisionTypeSelector collisionTypeRef)
{
	sizeX = size.x;
	sizeY = size.y;

	collisionType = collisionTypeRef;

}