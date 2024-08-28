#include <SDL.h>
#include <stdio.h>

#include "WindowHandler.h"


WindowHandler::WindowHandler()
{

}
	SDL_Window* WindowHandler::createWindow(SDL_Window* gWindow, int SCREEN_WIDTH, int SCREEN_HEIGHT )
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL Error: &s\n", SDL_GetError());
			return NULL;
		}
		else
		{
			gWindow = SDL_CreateWindow("OpenGL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
			if ( gWindow == NULL )
			{
				printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
				return NULL;
			}
			else
			{
				return gWindow;
			}
		}
	}

	void WindowHandler::fitImageToScreen(SDL_Window* gWindow, int SCREEN_WIDTH, int SCREEN_HEIGHT, SDL_Surface* currentSurface, SDL_Surface* gScreenSurface)
	{
		SDL_Rect stretchRect;
		stretchRect.x = 0;
		stretchRect.y = 0;
		stretchRect.w = SCREEN_WIDTH;
		stretchRect.h = SCREEN_HEIGHT;
		SDL_BlitScaled(currentSurface, NULL, gScreenSurface, &stretchRect);
		SDL_UpdateWindowSurface(gWindow);
	}

	SDL_Surface* WindowHandler::getScreenSurface(SDL_Window* gWindow)
	{
		return SDL_GetWindowSurface(gWindow);
	}

