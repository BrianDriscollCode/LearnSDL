#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

// Utilities
#include "../Engine/Utilities/Enum/KeyPress.h"
#include "../Engine/Utilities/Enum/BoxCollision.h"


class Entity
{
public:
	glm::vec3 actualPosition;
	glm::vec3 currentPosition;
	glm::vec3 prevPosition;
	glm::vec2 size;

	Entity();

	void InitEntity(glm::vec3 startPosition, glm::vec2 initSize);
	void MoveEntity(float deltaTime, float alpha, KeyPress directionX, KeyPress directionY, BoxCollision collisionDirectionX, BoxCollision collisionDirectionY);
};

#endif