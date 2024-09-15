#include "Player.h"

Player::Player()
	:	debugOutput(true),
		playerMovementInput(),
		entityManager(ReferenceHelper::GetEntityManager()),
		entity(),
		collisionBox()
{
	// Start position
	initStartPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	
	// Size of collision box
	sizeX = 0.20f;
	sizeY = 0.20f;

	// Initialize Entity
	entity.InitEntity(initStartPosition, glm::vec2(sizeX, sizeY));
	uniqueId = entityManager->RegisterEntity(std::string("Player"), &entity);

	// Initialize Collision Box
	collisionBox.InitCollisionBox(sizeX, sizeY);
}

void Player::Tick()
{
	// Connect to states for movement and input
	playerMovementInput.MoveInput();

	// deltatime and alpha for movement interpolation
	float deltaTime = *ReferenceHelper::GetDeltaTime();
	float alpha = *ReferenceHelper::GetAlphaTime();

	//Check x and y axis for collisions
	collisionDirectionX = collisionBox.CalculateDirectionalCollisionX(entityManager->GetAllEntities(), &entity, uniqueId);
	collisionDirectionY = collisionBox.CalculateDirectionalCollisionY(entityManager->GetAllEntities(), &entity, uniqueId);

	// Get Movement State
	currentXMovementState = playerMovementInput.currentXMovementState;
	currentYMovementState = playerMovementInput.currentYMovementState;

	// Move Entity
	entity.MoveEntity(deltaTime, alpha, currentXMovementState, currentYMovementState, collisionDirectionX, collisionDirectionY);
}

void Player::DrawSelf()
{
	Renderer* renderer = ReferenceHelper::GetRenderer();
	renderer->drawer.DrawSquare(entity, GREEN, glm::vec2(sizeX, sizeY));
}
