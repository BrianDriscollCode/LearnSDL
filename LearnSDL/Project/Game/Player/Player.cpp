#include "Player.h"

Player::Player()
	: entity(glm::vec3(0.0f, 0.0f, 0.0f)), debugOutput(true), playerMovementInput()
{
};

void Player::Tick()
{

	// Connect to states for movement and input
	playerMovementInput.MoveInput();

	// move player across screen using interpolation and GLM
	float deltaTime = *ReferenceHelper::GetDeltaTime();
	float alpha = *ReferenceHelper::GetAlphaTime();
	entity.MoveEntity(deltaTime, alpha, playerMovementInput.currentXMovementState, playerMovementInput.currentYMovementState);

}

void Player::DrawSelf()
{
	SDL_Window* gWindow = ReferenceHelper::GetWindow();
	Renderer* renderer = ReferenceHelper::GetRenderer();

	renderer->drawer.DrawSquare(gWindow, entity);
	//renderer->drawer.EndDraw();
	
}

