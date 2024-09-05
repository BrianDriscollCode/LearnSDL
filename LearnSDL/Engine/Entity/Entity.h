#ifndef ENTITY_H
#define ENTITY_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../Engine/Utilities/Enum/KeyPress.h"

class Entity
{
public:
	glm::vec3 position;

	Entity();

	void MoveEntity(float deltaTime, KeyPress directionX, KeyPress directionY);
	//void update(float deltaTime);
};

#endif