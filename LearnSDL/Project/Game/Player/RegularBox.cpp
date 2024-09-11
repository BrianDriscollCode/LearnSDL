#include "RegularBox.h"

RegularBox::RegularBox(glm::vec3 initPos)
	:entityManager(ReferenceHelper::GetEntityManager())
{
	uniqueId = entityManager->CreateEntity(initPos);
}

void RegularBox::Tick()
{

}

void RegularBox::DrawSelf()
{
	SDL_Window* gWindow = ReferenceHelper::GetWindow();
	Renderer* renderer = ReferenceHelper::GetRenderer();
	Entity& entity = *entityManager->GetEntity(uniqueId);

	renderer->drawer.DrawSquare(entity, RED, glm::vec2(1.0f, 1.0f));
}