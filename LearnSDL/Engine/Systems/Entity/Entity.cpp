
#include "Entity.h"
#include <iostream>

Entity::Entity()
{

}

void Entity::InitEntity(glm::vec3 startPosition)
{
	actualPosition = startPosition;
	currentPosition = startPosition;


}

void Entity::MoveEntity(float deltaTime, float alpha, KeyPress directionX, KeyPress directionY, BoxCollision collisionDirectionX, BoxCollision collisionDirectionY)
{

	prevPosition = currentPosition;

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




