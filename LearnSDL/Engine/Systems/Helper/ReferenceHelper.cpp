#include "ReferenceHelper.h"


// Register and manage window
void ReferenceHelper::RegisterWindow(SDL_Window* gWindow) 
{
	Instance().gWindow = gWindow;
};

SDL_Window* ReferenceHelper::GetWindow() 
{
	return Instance().gWindow;
}

// Register and manage renderer

void ReferenceHelper::RegisterRenderer(Renderer* renderer)
{
	Instance().renderer = renderer;
}

Renderer* ReferenceHelper::GetRenderer()
{
	return Instance().renderer;
}

ReferenceHelper& ReferenceHelper::Instance()
{
	static ReferenceHelper instance;
	return instance;
}