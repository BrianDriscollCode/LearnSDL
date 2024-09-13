#include "RegularBox.h"

RegularBox::RegularBox(glm::vec3 initPos)
	:entityManager(ReferenceHelper::GetEntityManager()), entity()
{
	entity.InitEntity(glm::vec3(0.75f, 0.55f, 0.0f));
	entityManager->RegisterEntity(std::string("enemy"), &entity);
	//uniqueId = entityManager->CreateEntity(initPos);
}

void RegularBox::Tick()
{

}

void RegularBox::DrawSelf()
{
	Renderer* renderer = ReferenceHelper::GetRenderer();

	renderer->drawer.DrawSquare(entity, RED, glm::vec2(1.0f, 1.0f));
}