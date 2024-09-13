#include "Player.h"
#include <string>

Player::Player()
	: entityManager(ReferenceHelper::GetEntityManager()), debugOutput(true), playerMovementInput()
{
	//uniqueId = entityManager->CreateEntity(glm::vec3(0.0f, 0.0f, 0.0f));
	size = 1.0f; // defines square size
	collisionSize = (size / 5.0f) + 0.01f; // defines collision boundaries calculated by experimentation
}

void Player::Tick()
{
	// Connect to states for movement and input
	playerMovementInput.MoveInput();

	// move player across screen using interpolation and GLM
	float deltaTime = *ReferenceHelper::GetDeltaTime();
	float alpha = *ReferenceHelper::GetAlphaTime();

	//collisionDirectionX = entityManager->CalculateDirectionalCollisions(uniqueId, true, false, collisionSize);
	//collisionDirectionY = entityManager->CalculateDirectionalCollisions(uniqueId, false, true, collisionSize);

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
	Renderer* renderer = ReferenceHelper::GetRenderer();
	Entity& entity = *entityManager->GetEntity(uniqueId);

	renderer->drawer.DrawSquare(entity, GREEN, glm::vec2(size, size));
}

