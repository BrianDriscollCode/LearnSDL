#ifndef REFERENCEHELPER_H
#define REFERENCEHELPER_H

#include <SDL.h>
#include "../Engine/Renderer/Renderer.h"

// How to get this reference helper easily passable, with references into project code?
class ReferenceHelper
{
public:

	static void RegisterWindow(SDL_Window* window);
	static SDL_Window* GetWindow();

	static void RegisterRenderer(Renderer* renderer);
	static Renderer* GetRenderer();

private:
	static ReferenceHelper& Instance();

	//ReferenceHelper() = default;

	SDL_Window* gWindow = nullptr;
	Renderer* renderer = nullptr;
};

#endif