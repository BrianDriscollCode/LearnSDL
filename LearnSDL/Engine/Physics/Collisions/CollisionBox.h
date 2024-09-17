#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

// Utilities
#include "../Engine/Utilities/Enum/CollisionTypeSelector.h"

class CollisionBox
{
public:
	CollisionBox();

	void InitCollisionBox(glm::vec2 size, CollisionTypeSelector collisionTypeRef);

	float sizeX;
	float sizeY;
	CollisionTypeSelector collisionType;
};


#endif