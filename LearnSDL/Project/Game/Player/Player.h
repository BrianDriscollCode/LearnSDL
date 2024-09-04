#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

#include "../Engine/Entity/Entity.h"
#include "../Engine/Systems/Helper/ReferenceHelper.h"
#include "../Engine/Renderer/Renderer.h"

class Player
{
public:
	Player();
	Entity playerObject;

	void DrawSelf();
	SDL_Window* gWindow;
	Renderer* renderer;
};

#endif 
