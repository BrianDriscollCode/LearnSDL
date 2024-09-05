#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>


// Engine Systems
#include "../Engine/Entity/Entity.h"
#include "../Engine/Systems/Helper/ReferenceHelper.h"
#include "../Engine/Renderer/Renderer.h"
#include "../Engine/Debug/DebugOutput.h"

// Project Scripts
#include "../Project/Game/Player/PlayerMovement.h"

class Player
{
public:
	Player();
	Entity entity;
	DebugOutput debugOutput;
	PlayerMovement playerMovement;

	void Tick();

	void DrawSelf();
	SDL_Window* gWindow;
	Renderer* renderer;
};

#endif 
