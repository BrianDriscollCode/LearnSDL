#include "RegularBox.h"

RegularBox::RegularBox()
	: entity(glm::vec3(0.5f, 0.5f, 0.0f))
{

}

void RegularBox::Tick()
{

}

void RegularBox::DrawSelf()
{
	SDL_Window* gWindow = ReferenceHelper::GetWindow();
	Renderer* renderer = ReferenceHelper::GetRenderer();

	renderer->drawer.DrawSquare(gWindow, entity);
}