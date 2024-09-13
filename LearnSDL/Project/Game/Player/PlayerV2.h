#ifndef PLAYERV2_H
#define PLAYERV2_H

#include <SDL.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>


// Engine Systems
#include "../Engine/Systems/Entity/Entity.h"
#include "../Engine/Physics/Collisions/CollisionBox.h"
#include "../Engine/Utilities/Helper/ReferenceHelper.h"
#include "../Engine/Renderer/Renderer.h"
#include "../Engine/Debug/DebugOutput.h"

// Project Scripts
#include "../Project/Game/Player/PlayerMovementInput.h"

// Utilities
#include "../Engine/Utilities/Enum/Color.h"
#include "../Engine/Utilities/Enum/BoxCollision.h"

class PlayerV2
{
public:
	PlayerV2();

	DebugOutput debugOutput;
	PlayerMovementInput playerMovementInput;
	Entity entity;
	CollisionBox collisionBox;
	EntityManager* entityManager;


	BoxCollision collisionDirectionX = NO_COL;
	BoxCollision collisionDirectionY = NO_COL;

	int uniqueId;
	float sizeX;
	float sizeY;
	glm::vec3 position;

	void Tick();
	void DrawSelf();

};

#endif 

