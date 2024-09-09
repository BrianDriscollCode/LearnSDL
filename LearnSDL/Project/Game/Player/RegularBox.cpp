#include "RegularBox.h"

RegularBox::RegularBox()
	:entityManager(ReferenceHelper::GetEntityManager())
{
	uniqueId = entityManager->CreateEntity(glm::vec3(0.5f, 0.5f, 0.0f));
}

void RegularBox::Tick()
{

}

void RegularBox::DrawSelf()
{
	SDL_Window* gWindow = ReferenceHelper::GetWindow();
	Renderer* renderer = ReferenceHelper::GetRenderer();
	Entity& entity = *entityManager->GetEntity(uniqueId);

	renderer->drawer.DrawSquare(entity, RED, glm::vec2(0.25f, 0.25f));
}