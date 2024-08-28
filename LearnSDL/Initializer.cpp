
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

// Rendering External Libraries
#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL_opengl.h>

// Rendering Internal
#include "../Engine/Renderer/InitializeRenderer.h";
#include "../Engine/Renderer/Shaders/Shader.h"

// Systems Manager
#include "../Engine/Systems/SystemManager.h"
#include "../Engine/Systems/Loaders/SurfaceLoader.h"
#include "../Engine/Systems/Handlers/InputHandler.h"
#include "../Engine/Systems/Handlers/WindowHandler.h"
#include "../Engine/Systems/Managers/CallbackEventManager.h"
#include "../Engine/Systems/Managers/SubEmitEventManager.h"

// Testing
#include "../Engine/Systems/TestBed.h"


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

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ TOTAL ];

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed image
SDL_Surface* gStretchedSurface = NULL;


// Load Systems
//
SystemManager systemManager;

GLuint shaderProgram;
GLuint VAO, VBO;
InitializeRenderer renderer(VAO, VBO, shaderProgram);
// Function to initialize shaders and buffers


bool init()
{
	//Initialization flag
	bool success = true;
	std::cout << " Flag 1 " << std::endl;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	// Handles window creation logic
	//gWindow = systemManager.windowHandler.createWindow(gWindow, SCREEN_WIDTH, SCREEN_HEIGHT);
	gWindow = SDL_CreateWindow("OpenGL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	std::cout << " flag2" << std::endl;
	if (gWindow == NULL)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Create the OpenGL context
		SDL_GLContext glContext = SDL_GL_CreateContext(gWindow);

		if (glContext == NULL)
		{
			printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Initialize GLEW (this should be done after creating the OpenGL context)
			glewExperimental = GL_TRUE;
			GLenum glewError = glewInit();
			if (glewError != GLEW_OK)
			{
				printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
				success = false;
			}
			else
			{
				renderer.StartRenderer();
			}

			// Use Vsync
			if (SDL_GL_SetSwapInterval(1) < 0)
			{
				printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
			}

			// Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			std::cout << " Flag3 " << std::endl;
	
		}
	}

	return success;
}



void close()
{
	
	renderer.terminateRenderer();
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

	std::cout << " flag 6 " << std::endl;

	if (!init()) {
		printf("Failed to initialize!\n");
	}
	else {
		bool quit = false;
		SDL_Event eventObject;

		InputHandler& inputHandler = systemManager.inputHandler;
		CallbackEventManager& callbackEventManager = systemManager.callbackEventManager;
		SubEmitEventManager& subEmitEventManager = systemManager.subEmitEventManager;
		TestBed testBed(systemManager);

		testBed.testEmit();
		std::cout << " Flag 4 " << std::endl;
		// Assign actions
		inputHandler.setAction(SDLK_UP, [eventObject, &subEmitEventManager]() { subEmitEventManager.emit("EnemyKilled", eventObject); });
		inputHandler.setAction(SDLK_DOWN, [eventObject, &subEmitEventManager]() { subEmitEventManager.emit("PlayerSaved", eventObject); });
		inputHandler.setAction(SDLK_LEFT, []() { printf("Left key pressed\n"); });
		inputHandler.setAction(SDLK_RIGHT, []() { printf("Right key pressed\n"); });
		inputHandler.setAction(SDLK_ESCAPE, []() { close(); });

		// Set up events
		/*callbackEventManager.registerListener(SDL_KEYDOWN, [](const SDL_Event& event) {
			if (event.key.keysym.sym == SDLK_UP)
			{
				printf("up key event!\n");
			}
		});*/

		subEmitEventManager.registerListener("EnemyKilled", runDie);
		subEmitEventManager.registerListener("PlayerSaved", playerAlive);


		Shader shader("./Engine/Renderer/Resources/BasicSquare.vert", "./Engine/Renderer/Resources/BasicSquare.frag");

		while (!quit) {
			while (SDL_PollEvent(&eventObject) != 0)
			{
				callbackEventManager.processEvent(eventObject);
				inputHandler.handleEvents(eventObject);
			}
			// Clear the color buffer
			glClear(GL_COLOR_BUFFER_BIT);

			// Draw the blue box
			//glUseProgram(shaderProgram);
			shader.use();
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			// Swap the OpenGL buffers
			SDL_GL_SwapWindow(gWindow);
			
		}
	}

	close();
	return 0;
}
