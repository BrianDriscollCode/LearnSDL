#include "Player.h"

Player::Player()
	:	debugOutput(true),
		playerMovementInput(),
		entityManager(ReferenceHelper::GetEntityManager()),
		entity(),
		collisionHandler()
{
	// Start position
	initStartPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	
	// Size of drawing and collision
	sizeX = 0.20f;
	sizeY = 0.20f;
	collisionSizeX = 0.20f;
	collisionSizeY = 0.20f;


	// Initialize Entity
	entity.InitEntity(initStartPosition, glm::vec2(sizeX, sizeY), glm::vec2(collisionSizeX, collisionSizeY), CollisionTypeSelector::PHYSICS);
	uniqueId = entityManager->RegisterEntity(std::string("Player"), &entity);

	// Initialize Collision Box
	collisionHandler.InitCollisionBox(collisionSizeX, collisionSizeY);
}

void Player::Tick()
{
	// Connect to states for movement and input
	playerMovementInput.MoveInput();

	// deltatime and alpha for movement interpolation
	float deltaTime = *ReferenceHelper::GetDeltaTime();
	float alpha = *ReferenceHelper::GetAlphaTime();

	//Check x and y axis for collisions
	collisionDirectionX = collisionHandler.CalculateDirectionalCollisionX(entityManager->GetAllEntities(), &entity, uniqueId);
	collisionDirectionY = collisionHandler.CalculateDirectionalCollisionY(entityManager->GetAllEntities(), &entity, uniqueId);

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
