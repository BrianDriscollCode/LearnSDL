#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

// Engine
#include "../Engine/Physics/Collisions/CollisionBox.h"

// Utilities
#include "../Engine/Utilities/Enum/KeyPress.h"
#include "../Engine/Utilities/Enum/BoxCollision.h"
#include "../Engine//Utilities/Enum/CollisionTypeSelector.h"

class Entity
{
public:
	Entity();

	glm::vec3 actualPosition;
	glm::vec3 currentPosition;
	glm::vec3 prevPosition;
	glm::vec2 size;
	glm::vec2 collisionSize;

	CollisionBox collisionBox;

	void InitEntity(glm::vec3 startPosition, glm::vec2 initSize, glm::vec2 initCollisionSize, CollisionTypeSelector collisionType);
	void MoveEntity(float deltaTime, float alpha, KeyPress directionX, KeyPress directionY, BoxCollision collisionDirectionX, BoxCollision collisionDirectionY);
};

#endif