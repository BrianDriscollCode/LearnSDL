#include "RegularBox.h"

RegularBox::RegularBox(glm::vec3 initPos, glm::vec2 size)
	:entityManager(ReferenceHelper::GetEntityManager()), entity()
{
	sizeX = size.x;
	sizeY = size.y;

	entity.InitEntity(glm::vec3(initPos), glm::vec2(sizeX, sizeY));
	entityManager->RegisterEntity(std::string("enemy"), &entity);
	//uniqueId = entityManager->CreateEntity(initPos);
}

void RegularBox::Tick()
{

}

void RegularBox::DrawSelf()
{
	Renderer* renderer = ReferenceHelper::GetRenderer();

	renderer->drawer.DrawSquare(entity, RED, glm::vec2(sizeX, sizeY));
}