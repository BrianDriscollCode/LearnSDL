#include "Player.h"

Player::Player()
	: entity(), gWindow(), debugOutput(true), playerMovement()
{
};

void Player::Tick()
{
	DrawSelf();

	float deltaTime = *ReferenceHelper::GetDeltaTime();
	playerMovement.MoveInput();
	entity.MoveEntity(deltaTime, playerMovement.currentXMovementState, playerMovement.currentYMovementState);

}

void Player::DrawSelf()
{
	SDL_Window* gWindow = ReferenceHelper::GetWindow();
	Renderer* renderer = ReferenceHelper::GetRenderer();

	renderer->drawer.DrawSquare(gWindow, entity);
	
}

