
#include "Entity.h"


#include <iostream>
Entity::Entity()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Entity::MoveEntity(float deltaTime, KeyPress directionX, KeyPress directionY)
{

	if (directionX == RIGHT)
	{
		position.x += 0.5f * deltaTime;
	}
	else if (directionX == LEFT)
	{
		position.x -= 0.5f * deltaTime;
	}

	if (directionY == UP)
	{
		position.y += 0.5f * deltaTime;
	}
	else if (directionY == DOWN)
	{
		position.y -= 0.5f * deltaTime;
	}
	//std::cout << "Delta Time: " << deltaTime * 0.5f << std::endl;
}



