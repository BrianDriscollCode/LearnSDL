#include "Player.h"
#include <string>

Player::Player()
	: entityManager(ReferenceHelper::GetEntityManager()), debugOutput(true), playerMovementInput()
{
	uniqueId = entityManager->CreateEntity(glm::vec3(0.0f, 0.0f, 0.0f));
}

void Player::Tick()
{
	// Connect to states for movement and input
	playerMovementInput.MoveInput();

	// move player across screen using interpolation and GLM
	float deltaTime = *ReferenceHelper::GetDeltaTime();
	float alpha = *ReferenceHelper::GetAlphaTime();

	collisionDirectionX = entityManager->CalculateDirectionalCollisions(uniqueId, true, false);
	collisionDirectionY = entityManager->CalculateDirectionalCollisions(uniqueId, false, true);

	//printf("x: " + collisionDirectionX);
	//printf("y: " + collisionDirectionY);

	entityManager->GetEntity(uniqueId)->MoveEntity(deltaTime, alpha, playerMovementInput.currentXMovementState, playerMovementInput.currentYMovementState, collisionDirectionX, collisionDirectionY);

	/*if (isColliding)
	{
		printf("Is Colliding");
	}*/
}

void Player::DrawSelf()
{
	SDL_Window* gWindow = ReferenceHelper::GetWindow();
	Renderer* renderer = ReferenceHelper::GetRenderer();
	Entity& entity = *entityManager->GetEntity(uniqueId);

	renderer->drawer.DrawSquare(entity, GREEN, glm::vec2(1.0f, 1.0f));
}

