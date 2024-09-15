#ifndef REGULARBOX_H
#define REGULARBOX_H

// External Libraries
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

// Engine Systems
#include "../Engine/Utilities/Helper/ReferenceHelper.h"
#include "../Engine/Systems/Entity/Entity.h"
#include "../Engine/Systems/Entity/EntityManager.h"

// Utilities
#include "../Engine/Utilities/Enum/Color.h"

class RegularBox
{
public:
	RegularBox(glm::vec3 initPos, glm::vec2 size);
	EntityManager* entityManager;
	Entity entity;
	float sizeX; 
	float sizeY;

	int uniqueId;

	void Tick();
	void DrawSelf();

};


#endif