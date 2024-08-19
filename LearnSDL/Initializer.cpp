
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

//Systems Manager
#include "../Engine/Systems/SystemManager.h"

#include "../Engine/Systems/Loaders/SurfaceLoader.h"
#include "../Engine/Systems/Handlers/InputHandler.h"
#include "../Engine/Systems/Handlers/WindowHandler.h"
#include "../Engine/Systems/Managers/EventManager.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 900;

//Key press surfaces constants
enum KeyPressSurfaces
{
	DEFAULT,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	TOTAL
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
SDL_Surface* gKeyPressSurfaces[ TOTAL ];

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed image
SDL_Surface* gStretchedSurface = NULL;


// Load Systems
//
SystemManager systemManager;

bool init()
{
	//Initialization flag
	bool success = true;

	// Handles window creation logic
	gWindow = systemManager.windowHandler.createWindow(gWindow, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (gWindow == NULL)
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
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

	SurfaceLoader& surfaceLoader = systemManager.surfaceLoader;
	//Loading success flag
	bool success = true;

	//Load default surface
	gKeyPressSurfaces[ DEFAULT ] = surfaceLoader.loadSurface( "Assets/keys/press.bmp", gScreenSurface );
	
	if( gKeyPressSurfaces[ DEFAULT ] == NULL )
	{
		printf( "Failed to load default image!\n" );
		success = false;
	}
	else
	{
		printf("Image Loaded Correctly!\n");
	}

	//Load up surface
	gKeyPressSurfaces[ UP ] = surfaceLoader.loadSurface( "Assets/keys/up.bmp", gScreenSurface );
	
	if( gKeyPressSurfaces[ UP ] == NULL )
	{
		printf( "Failed to load up image!\n" );
		success = false;
	}
	else
	{
		printf("Image Loaded Correctly!\n");
	}

	//Load down surface
	gKeyPressSurfaces[ DOWN ] = surfaceLoader.loadSurface( "Assets/keys/down.bmp", gScreenSurface );
	
	if( gKeyPressSurfaces[ DOWN ] == NULL )
	{
		printf( "Failed to load down image!\n" );
		success = false;
	}
	else
	{
		printf("Image Loaded Correctly!\n");
	}

	//Load left surface
	gKeyPressSurfaces[ LEFT ] = surfaceLoader.loadSurface( "Assets/keys/left.bmp", gScreenSurface );
	
	if( gKeyPressSurfaces[ LEFT ] == NULL )
	{
		printf( "Failed to load left image!\n" );
		success = false;
	}

	//Load right surface
	gKeyPressSurfaces[ RIGHT ] = surfaceLoader.loadSurface( "Assets/keys/right.bmp", gScreenSurface );
	
	if( gKeyPressSurfaces[ RIGHT ] == NULL )
	{
		printf( "Failed to load right image!\n" );
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
	for( int i = 0; i < TOTAL; ++i )
	{
		SDL_FreeSurface( gKeyPressSurfaces[ i ] );
		gKeyPressSurfaces[ i ] = NULL;
	}

	//Destroy window
	SDL_DestroyWindow( gWindow );
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
			SDL_Surface* currentSurface = gKeyPressSurfaces[DEFAULT];
			SDL_Event eventObject;

			InputHandler& inputHandler = systemManager.inputHandler;
			EventManager& eventManager = systemManager.eventManager;

			eventManager.registerListener(SDL_KEYDOWN, [](const SDL_Event& event) {
				if (event.key.keysym.sym == SDLK_UP)
				{
					printf("up key event!");
				}
			});

		

			// Assign actions
			inputHandler.setAction(SDLK_UP, []() { printf("Down key pressed\n"); });
			inputHandler.setAction(SDLK_DOWN, []() { printf("Down key pressed\n"); });
			inputHandler.setAction(SDLK_LEFT, []() { printf("Left key pressed\n"); });
			inputHandler.setAction(SDLK_RIGHT, []() { printf("Right key pressed\n"); });


			while (!quit) {

				while (SDL_PollEvent(&eventObject) != 0)
				{
					eventManager.processEvent(eventObject);
					inputHandler.handleEvents(eventObject);
				}

				systemManager.windowHandler.fitImageToScreen(gWindow, SCREEN_WIDTH, SCREEN_HEIGHT, currentSurface, gScreenSurface);
			}
		}
	}

	close();
	return 0;
}
