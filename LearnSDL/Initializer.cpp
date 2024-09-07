#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

// Rendering External Libraries
#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <chrono>

// Rendering Internal
#include "../Engine/Renderer/Renderer.h";

// Systems Manager
#include "../Engine/Systems/SystemManager.h"
#include "../Engine/Systems/Loaders/SurfaceLoader.h"
#include "../Engine/Systems/Handlers/InputHandler.h"
#include "../Engine/Systems/Handlers/WindowHandler.h"
#include "../Engine/Systems/Managers/CallbackEventManager.h"
#include "../Engine/Systems/Managers/SubEmitEventManager.h"
#include "../Engine/Debug/DebugOutput.h"

// Helpers
#include "../Engine/Utilities/Helper/ReferenceHelper.h"

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

void close(Renderer* renderer)
{
	// Terminate renderer, window, and SDL
	renderer->TerminateRenderer();
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}


int main(int argc, char* args[]) {
    // Initialize SDL and create window, load media, start renderer, etc.
    bool initializationSuccess = init();
	

    if (!initializationSuccess) {
        printf("Failed to initialize!\n");
		return -1;
    }
    
        bool quit = false;

		// OpenGL Rendering
		Renderer renderer(gWindow);

        SDL_Event eventObject;

        InputHandler& inputHandler = systemManager.inputHandler;
        CallbackEventManager& callbackEventManager = systemManager.callbackEventManager;
        SubEmitEventManager& subEmitEventManager = systemManager.subEmitEventManager;
        DebugOutput debugOutput(true);

		float alpha = 0.0f;
		float frameTime = 0.0f;
		float deltaTime = 0.0f;

        // Initiate Helper references
        ReferenceHelper::RegisterWindow(gWindow);
        ReferenceHelper::RegisterRenderer(&renderer);
        ReferenceHelper::RegisterEventObject(&eventObject);
		ReferenceHelper::RegisterAlphaTime(&alpha);
		ReferenceHelper::RegisterDeltaTime(&deltaTime);
 

        // Initialize Game Project
        ProjectInitializer projectInitializer(inputHandler, subEmitEventManager, eventObject, renderer, gWindow);
        projectInitializer.InitializeGameCode();
        projectInitializer.InitializeLevel();

        // Close Engine Logic
        inputHandler.setAction(SDLK_ESCAPE, [&renderer]() { close(&renderer); });

        // Renderer Shapes
        renderer.Init();

		// 16.67 ms per frame
		const float targetFrameTime = 1000.0f / 60.0f;
		// warm up to stabilize frame rate
		int warmupFrames = 10;
		bool showFPS = false;

		while (!quit) {
			// Start frame timing
			// Captures the current time in milliseconds using SDL’s
			Uint32 startTicks = SDL_GetTicks();

			// Poll for events
			while (SDL_PollEvent(&eventObject) != 0) {
				callbackEventManager.processEvent(eventObject);
				inputHandler.handleEvents(eventObject);
				projectInitializer.InPollCode(eventObject);
			}

			glClear(GL_COLOR_BUFFER_BIT);
			// Game update logic
			projectInitializer.InLoopCode();
			renderer.drawer.EndDraw();
			// Clear the color buffer
			

			// End frame timing
			Uint32 endTicks = SDL_GetTicks();
			Uint64 endPerf = SDL_GetPerformanceCounter();

			// Calculate deltaTime in seconds
			deltaTime = (endTicks - startTicks) / 1000.0f;

			// Update interval (fixed timestep for interpolation)
			float updateInterval = 1.0f / 60.0f;  // 60 FPS fixed timestep

			// Calculates the interpolation factor based on the frame time and fixed timestep. 
			// This is used to smoothly interpolate between the last and current frame states. 
			// endTicks - startTicks gives the elapsed time in performance counter units, and 
			// dividing it by the product of SDL_GetPerformanceFrequency() and updateInterval 
			// normalizes it to a value between 0 and 1.
			alpha = (endTicks - startTicks) / (SDL_GetPerformanceFrequency() * updateInterval);

			// Manage FPS: Delay if the frame time is less than target frame time
			// Re-calculates the frame time in milliseconds, which is the time elapsed since startTicks.
			float frameTime = (endTicks - startTicks);
			
			if (warmupFrames > 0)
			{
				warmupFrames--;
			}
			else if (frameTime < targetFrameTime) 
			{
				SDL_Delay(targetFrameTime - frameTime);
			}

			// Calculate and display FPS
			if (showFPS)
			{
				float actualFrameTime = SDL_GetTicks() - startTicks; // Actual frame time after delay
				float fps = 1000.0f / actualFrameTime; // FPS is 1000 ms divided by frame time in ms
				std::cout << "Current FPS: " << fps << std::endl;
			}
			
			
		
    }

    close(&renderer);
    return 0;
}