
#include "Entity.h"

Entity::Entity()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Entity::MoveEntity()
{
	position.x += 0.01f;
}



