
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

// Rendering External Libraries
#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL_opengl.h>

// Rendering Internal
#include "../Engine/Renderer/Renderer.h";

// Systems Manager
#include "../Engine/Systems/SystemManager.h"
#include "../Engine/Systems/Loaders/SurfaceLoader.h"
#include "../Engine/Systems/Handlers/InputHandler.h"
#include "../Engine/Systems/Handlers/WindowHandler.h"
#include "../Engine/Systems/Managers/CallbackEventManager.h"
#include "../Engine/Systems/Managers/SubEmitEventManager.h"

// Testing
#include "../Engine/Systems/TestBed.h"

// Game
#include "./Project/ProjectInitializer.h"

// Screen dimension constants
const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 900;

// Key press surfaces constants
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

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// Load Systems made with SDL
SystemManager systemManager;

// OpenGL Rendering
Renderer renderer;

bool initGLEW()
{
	// Initialize GLEW (this should be done after creating the OpenGL context)
	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
		return false;
	}

	return true;
}

bool init()
{
	//Initialization flag
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	// Handles window creation logic
	// 
	// Uses SDL_WINDOW_OPENGL
	gWindow = systemManager.windowHandler.createWindow(gWindow, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (gWindow == NULL)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Create the OpenGL context
		SDL_GLContext glContext = SDL_GL_CreateContext(gWindow);

		// Check for context and initialize GLEW and Renderer if it exists
		if (glContext == NULL)
		{
			printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			
			bool glewInitialized = initGLEW();

			if (glewInitialized)
			{
				renderer.StartRenderer();
			}
		}
	}

	return success;
}


void close()
{
	
	renderer.TerminateRenderer();
	// Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// Quit SDL subsystems
	SDL_Quit();
}

void runDie(const SDL_Event& event)
{
	printf("DEATH RAN - runDie :: function\n");
}

void playerAlive(const SDL_Event& event)
{
	printf("ALIVE RAN - playerAlive :: function\n");
}

int main(int argc, char* args[]) {
	
	// Initialize SDL and create window, load media, etc.

	bool intializationSuccess = init();

	if (!intializationSuccess) {
		printf("Failed to initialize!\n");
	}
	else {
		bool quit = false;
		SDL_Event eventObject;

		InputHandler& inputHandler = systemManager.inputHandler;
		CallbackEventManager& callbackEventManager = systemManager.callbackEventManager;
		SubEmitEventManager& subEmitEventManager = systemManager.subEmitEventManager;
		TestBed testBed(systemManager);

		//testBed.testEmit();

		//// Assign actions
		//inputHandler.setAction(SDLK_UP, [eventObject, &subEmitEventManager]() { subEmitEventManager.emit("EnemyKilled", eventObject); });
		//inputHandler.setAction(SDLK_DOWN, [eventObject, &subEmitEventManager]() { subEmitEventManager.emit("PlayerSaved", eventObject); });
		//inputHandler.setAction(SDLK_LEFT, []() { printf("Left key pressed\n"); });
		//inputHandler.setAction(SDLK_RIGHT, []() { printf("Right key pressed\n"); });
		inputHandler.setAction(SDLK_ESCAPE, []() { close(); });

		//// Set up events
		///*callbackEventManager.registerListener(SDL_KEYDOWN, [](const SDL_Event& event) {
		//	if (event.key.keysym.sym == SDLK_UP)
		//	{
		//		printf("up key event!\n");
		//	}
		//});*/

		
		//subEmitEventManager.registerListener("PlayerSaved", playerAlive);


		subEmitEventManager.registerListener("EnemyKilled", runDie);

		inputHandler.setAction(SDLK_LEFT, []() { renderer.drawer.MoveSquare(); });


		// Initialize Game Project
		ProjectInitializer projectInitializer(inputHandler, subEmitEventManager, eventObject);
		projectInitializer.gameCode();


		// Game Loop
		while (!quit) {
			while (SDL_PollEvent(&eventObject) != 0)
			{
				callbackEventManager.processEvent(eventObject);
				inputHandler.handleEvents(eventObject);
			}
			// Clear the color buffer
			glClear(GL_COLOR_BUFFER_BIT);

			// Draw shapes from renderer
			renderer.RenderScene(gWindow);

			// Swap the OpenGL buffers
			//SDL_GL_SwapWindow(gWindow);
		}
	}

	close();
	return 0;
}
