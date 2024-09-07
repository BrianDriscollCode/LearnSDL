#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>


// Engine Systems
#include "../Engine/Entity/Entity.h"
#include "../Engine/Utilities/Helper/ReferenceHelper.h"
#include "../Engine/Renderer/Renderer.h"
#include "../Engine/Debug/DebugOutput.h"

// Project Scripts
#include "../Project/Game/Player/PlayerMovementInput.h"

class Player
{
public:
	Player();
	Entity entity;
	DebugOutput debugOutput;
	PlayerMovementInput playerMovementInput;

	void Tick();

	void DrawSelf();
};

#endif 
