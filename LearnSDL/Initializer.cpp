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

// Helpers
#include "../Engine/Systems/Helper/ReferenceHelper.h"

// Utilities
#include "../Engine/Utilities/Enum/KeyPress.h";

// Testing
#include "../Engine/Systems/TestBed.h"

// Game
#include "./Project/ProjectInitializer.h"

// Screen dimension constants
const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 900;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

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
				//renderer.StartRenderer();
			}
		}
	}

	return success;
}

void close()
{
	// Terminate renderer, window, and SDL
	renderer.TerminateRenderer();
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

int main(int argc, char* args[]) {
	
	// Initialize SDL and create window, load media, start renderer, etc.
	bool intializationSuccess = init();

	if (!intializationSuccess) {
		printf("Failed to initialize!\n");
	}
	else {
		bool quit = false;
		// Initiate SDL Event
		SDL_Event eventObject;

		// Initiate Engine Systems
		InputHandler& inputHandler = systemManager.inputHandler;
		CallbackEventManager& callbackEventManager = systemManager.callbackEventManager;
		SubEmitEventManager& subEmitEventManager = systemManager.subEmitEventManager;

		// Initiate Helpers
		ReferenceHelper::RegisterWindow(gWindow);
		ReferenceHelper::RegisterRenderer(&renderer);

		// Initialize Game Project
		ProjectInitializer projectInitializer(inputHandler, subEmitEventManager, eventObject, renderer, gWindow);
		projectInitializer.InitializeGameCode();
		projectInitializer.InitializeLevel();

		// Close Engine Logic
		inputHandler.setAction(SDLK_ESCAPE, []() { close(); });

		// Framerate Variables
		const int FPS = 60;
		const int frameDelay = 1000 / FPS;
		Uint32 frameStart;
		int frameTime;

		// Renderer Shapes
		renderer.Init();

		// Game Loop
		while (!quit) {
			frameStart = SDL_GetTicks();

			// Poll for events
			while (SDL_PollEvent(&eventObject) != 0)
			{
				callbackEventManager.processEvent(eventObject);
				inputHandler.handleEvents(eventObject);
				projectInitializer.InPollCode(eventObject);
			}

			projectInitializer.InLoopCode();
			//SDL_GL_SwapWindow(gWindow);

			// Draw shapes from renderer
			//renderer.drawer.DrawSquare(gWindow);

			// Manage framerate
			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime) {
				SDL_Delay(frameDelay - frameTime);
			}

			// Clear the color buffer
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}

	close();
	return 0;
}
