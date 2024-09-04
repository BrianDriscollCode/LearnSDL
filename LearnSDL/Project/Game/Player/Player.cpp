#include "Player.h"

Player::Player()
	: playerObject(), gWindow()
{
};

void Player::DrawSelf()
{
	SDL_Window* gWindow = ReferenceHelper::GetWindow();
	Renderer* renderer = ReferenceHelper::GetRenderer();

	renderer->drawer.DrawSquare(gWindow, playerObject);
	
}

