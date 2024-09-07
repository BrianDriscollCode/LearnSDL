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

// Register and manage EventObject

void ReferenceHelper::RegisterEventObject(SDL_Event* eventObject)
{
	Instance().eventObject = eventObject;
}

SDL_Event* ReferenceHelper::GetEventObject()
{
	return Instance().eventObject;
}

// Register and manage alphaTime

void ReferenceHelper::RegisterAlphaTime(float* alphaTime)
{
	Instance().alphaTime = alphaTime;
}

float* ReferenceHelper::GetAlphaTime()
{
	return Instance().alphaTime;
}

// Register and manage TargetFrameTime

void ReferenceHelper::RegisterDeltaTime(float* deltatime)
{
	Instance().deltaTime = deltatime;
}

float* ReferenceHelper::GetDeltaTime()
{
	return Instance().deltaTime;
}

// The Instance

ReferenceHelper& ReferenceHelper::Instance()
{
	static ReferenceHelper instance;
	return instance;
}