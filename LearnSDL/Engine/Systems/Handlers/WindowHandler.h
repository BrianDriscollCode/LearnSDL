#ifndef WINDOWHANDLER_H
#define WINDOWHANDLER_H

#include <SDL.h>

class WindowHandler
{
public:
	
	//Constructor
	WindowHandler();

	SDL_Window* createWindow(SDL_Window* gWindow, int SCREEN_WIDTH, int SCREEN_HEIGHT);

	void fitImageToScreen(SDL_Window* gWindow, int SCREEN_WIDTH, int SCREEN_HEIGHT, SDL_Surface* currentSurface, SDL_Surface* gScreenSurface);

	SDL_Surface* getScreenSurface(SDL_Window* gWindow);

};

#endif 