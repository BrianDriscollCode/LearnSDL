
#include "Entity.h"
#include <iostream>

Entity::Entity() {}

void Entity::InitEntity(glm::vec3 startPosition, glm::vec2 initSize, glm::vec2 initCollisionSize, CollisionTypeSelector collisionType)
{
	actualPosition = startPosition;
	currentPosition = startPosition;
	size = initSize;
	collisionSize = initCollisionSize;

	collisionBox.InitCollisionBox(glm::vec2(collisionSize.x, collisionSize.y), collisionType);
}

void Entity::MoveEntity(float deltaTime, float alpha, KeyPress directionX, KeyPress directionY, BoxCollision collisionDirectionX, BoxCollision collisionDirectionY)
{

	// set prev position for interpolation
	prevPosition = currentPosition;

	// move entity
	if (directionX == RIGHT && collisionDirectionX != RIGHT_COL)
	{
		currentPosition.x += 1.0f * deltaTime;
	}
	else if (directionX == LEFT && collisionDirectionX != LEFT_COL)
	{
		currentPosition.x -= 1.0f * deltaTime;
	}

	if (directionY == UP && collisionDirectionY != TOP_COL)
	{
		currentPosition.y += 1.0f * deltaTime;
	}
	else if (directionY == DOWN && collisionDirectionY != BOTTOM_COL)
	{
		currentPosition.y -= 1.0f * deltaTime;
	}

	// movement interpolation with formula
	actualPosition.x = prevPosition.x + alpha * (currentPosition.x - prevPosition.x);
	actualPosition.y = prevPosition.y + alpha * (currentPosition.y - prevPosition.y);
	// Debug output for positions and deltas
}





