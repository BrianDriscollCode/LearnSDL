
#include "Entity.h"
#include <iostream>

Entity::Entity(glm::vec3 startPosition)
{
	actualPosition = startPosition;
	currentPosition = startPosition;
}

void Entity::MoveEntity(float deltaTime, float alpha, KeyPress directionX, KeyPress directionY, BoxCollision collisionDirection)
{

	prevPosition = currentPosition;

	if (directionX == RIGHT && collisionDirection != RIGHT_COL)
	{
		currentPosition.x += 1.0f * deltaTime;
	}
	else if (directionX == LEFT && collisionDirection != LEFT_COL)
	{
		currentPosition.x -= 1.0f * deltaTime;
	}

	if (directionY == UP && collisionDirection != TOP_COL)
	{
		currentPosition.y += 1.0f * deltaTime;
	}
	else if (directionY == DOWN && collisionDirection != BOTTOM_COL)
	{
		currentPosition.y -= 1.0f * deltaTime;
	}

	//std::cout << "DeltaTime: " << deltaTime << std::endl;
	actualPosition.x = prevPosition.x + alpha * (currentPosition.x - prevPosition.x);
	actualPosition.y = prevPosition.y + alpha * (currentPosition.y - prevPosition.y);
}

//void Entity::RegisterSelfToEntityManager()
//{
//	EntityManager* entityManager = ReferenceHelper::GetEntityManager();
//	entityManager->RegisterEntity(std::string("object"), this);
//	
//}




