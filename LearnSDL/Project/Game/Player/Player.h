#ifndef PLAYER_H
#define PLAYER_H

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
#include "../Engine/Utilities/Enum/KeyPress.h"
#include "../Engine/Utilities/Enum/CollisionTypeSelector.h"

class Player
{
public:
	Player();

	DebugOutput debugOutput;
	PlayerMovementInput playerMovementInput;
	Entity entity;
	CollisionBox collisionBox;
	EntityManager* entityManager;

	BoxCollision collisionDirectionX = NO_COL;
	BoxCollision collisionDirectionY = NO_COL;

	KeyPress currentXMovementState;
	KeyPress currentYMovementState;

	int uniqueId;
	float sizeX;
	float sizeY;
	glm::vec3 initStartPosition;

	void Tick();
	void DrawSelf();

};

#endif 
