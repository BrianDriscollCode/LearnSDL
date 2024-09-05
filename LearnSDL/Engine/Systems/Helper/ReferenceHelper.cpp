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

// Register and manage DeltaTime

void ReferenceHelper::RegisterDeltaTime(float* deltaTime)
{
	Instance().deltaTime = deltaTime;
}

float* ReferenceHelper::GetDeltaTime()
{
	return Instance().deltaTime;
}

// Registert and manage EventObject

void ReferenceHelper::RegisterEventObject(SDL_Event* eventObject)
{
	Instance().eventObject = eventObject;
}

SDL_Event* ReferenceHelper::GetEventObject()
{
	return Instance().eventObject;
}

ReferenceHelper& ReferenceHelper::Instance()
{
	static ReferenceHelper instance;
	return instance;
}