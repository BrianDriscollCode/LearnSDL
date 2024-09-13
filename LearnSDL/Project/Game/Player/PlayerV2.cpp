#include "PlayerV2.h"

PlayerV2::PlayerV2()
	: debugOutput(true), playerMovementInput(), entityManager(ReferenceHelper::GetEntityManager()), entity(), collisionBox()
{

	position = glm::vec3(0.0f, 0.0f, 0.0f);
	sizeX = 1.0f;
	sizeY = 1.0f;

	// Initialize Entity
	entity.InitEntity(position);
	uniqueId = entityManager->RegisterEntity(std::string("Player"), &entity);

	// Initialize Collision Box
	collisionBox.InitCollisionBox(sizeX, sizeY);
}

void PlayerV2::Tick()
{
	// Connect to states for movement and input
	playerMovementInput.MoveInput();

	float deltaTime = *ReferenceHelper::GetDeltaTime();
	float alpha = *ReferenceHelper::GetAlphaTime();

	collisionDirectionX = collisionBox.CalculateDirectionalCollisionX(entityManager->GetAllEntities(), &entity, uniqueId);
	collisionDirectionY = collisionBox.CalculateDirectionalCollisionY(entityManager->GetAllEntities(), &entity, uniqueId);

	entityManager->GetEntity(uniqueId)->MoveEntity(deltaTime, alpha, playerMovementInput.currentXMovementState, playerMovementInput.currentYMovementState, collisionDirectionX, collisionDirectionY);
}

void PlayerV2::DrawSelf()
{
	Renderer* renderer = ReferenceHelper::GetRenderer();
	renderer->drawer.DrawSquare(entity, GREEN, glm::vec2(sizeX, sizeY));
}