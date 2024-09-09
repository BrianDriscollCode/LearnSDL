#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>


// Engine Systems
//#include "../Engine/Systems/Entity/Entity.h"
#include "../Engine/Utilities/Helper/ReferenceHelper.h"
#include "../Engine/Renderer/Renderer.h"
#include "../Engine/Debug/DebugOutput.h"

// Project Scripts
#include "../Project/Game/Player/PlayerMovementInput.h"

// Utilities
#include "../Engine/Utilities/Enum/Color.h"

class Player
{
public:
	Player();
	//Entity entity;
	DebugOutput debugOutput;
	PlayerMovementInput playerMovementInput;
	EntityManager* entityManager;

	void Tick();

	void DrawSelf();
	int uniqueId;
};

#endif 
