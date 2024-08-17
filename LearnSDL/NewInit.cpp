#include <SDL.h>
#include <stdio.h>
#include <string>

#include "../Engine/Systems/Loaders/SurfaceLoader.h"
#include "../Engine/Systems/Handlers/InputHandler.h"
#include "../Engine/Systems/Handlers/WindowHandler.h"



//Screen dimension constants
const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 900;

//Key press surfaces constants
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed image
SDL_Surface* gStretchedSurface = NULL;


// Load Systems
// 
//*Loaders
SurfaceLoader surfaceLoader;
//*Handlers
WindowHandler windowHandler;

bool init()
{
	//Initialization flag
	bool success = true;

	// Handles window creation logic
	gWindow = windowHandler.createWindow(gWindow, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (gWindow == NULL)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gScreenSurface = SDL_GetWindowSurface(gWindow);
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load default surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = surfaceLoader.loadSurface("Assets/keys/press.bmp", gScreenSurface);

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	else
	{
		printf("Image Loaded Correctly!\n");
	}

	//Load up surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = surfaceLoader.loadSurface("Assets/keys/up.bmp", gScreenSurface);

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load up image!\n");
		success = false;
	}
	else
	{
		printf("Image Loaded Correctly!\n");
	}

	//Load down surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = surfaceLoader.loadSurface("Assets/keys/down.bmp", gScreenSurface);

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("Failed to load down image!\n");
		success = false;
	}
	else
	{
		printf("Image Loaded Correctly!\n");
	}

	//Load left surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = surfaceLoader.loadSurface("Assets/keys/left.bmp", gScreenSurface);

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Failed to load left image!\n");
		success = false;
	}

	//Load right surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = surfaceLoader.loadSurface("Assets/keys/right.bmp", gScreenSurface);

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Failed to load right image!\n");
		success = false;
	}
	else
	{
		printf("Image Loaded Correctly!\n");
	}

	return success;
}

void close()
{
	//Deallocate surfaces
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
	{
		SDL_FreeSurface(gKeyPressSurfaces[i]);
		gKeyPressSurfaces[i] = NULL;
	}

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[]) {
	// Initialize SDL and create window, load media, etc.

	if (!init()) {
		printf("Failed to initialize!\n");
	}
	else {
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		}
		else {
			bool quit = false;
			SDL_Surface* currentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

			InputHandler inputHandler;

			while (!quit) {
				inputHandler.handleEvents(quit, currentSurface, gKeyPressSurfaces, KEY_PRESS_SURFACE_TOTAL);
				windowHandler.fitImageToScreen(gWindow, SCREEN_WIDTH, SCREEN_HEIGHT, currentSurface, gScreenSurface);
			}
		}
	}

	close();
	return 0;
}
