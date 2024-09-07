#ifndef ENTITY_H
#define ENTITY_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../Engine/Utilities/Enum/KeyPress.h"

class Entity
{
public:
	glm::vec3 actualPosition;
	glm::vec3 currentPosition;
	glm::vec3 prevPosition;

	Entity(glm::vec3 startPosition);

	void MoveEntity(float deltaTime, float alpha, KeyPress directionX, KeyPress directionY);
	//void update(float deltaTime);
};

#endif