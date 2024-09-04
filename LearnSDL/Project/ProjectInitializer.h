#ifndef PROJECTINITIALIZER_H
#define PROJECTINITIALIZER_H

#include <SDL.h>

// Systems
#include "../Engine/Systems/Handlers/InputHandler.h"
#include "../Engine/Systems/Managers/SubEmitEventManager.h"

// Renderer
#include "../Engine/Renderer/Renderer.h"

// Utilities
#include "../Engine/Utilities/Enum/KeyPress.h"

// Game Scripts
#include "../Project/Game/Player/PlayerMovement.h"
#include "../Project/Game/Player/Player.h"

// Utilities
#include "../Engine/Debug/DebugOutput.h"

class ProjectInitializer
{
public:
	ProjectInitializer
	(
		InputHandler& inputHandlerRef,
		SubEmitEventManager& subEmitEventManagerRef,
		SDL_Event& eventObjectRef,
		Renderer& rendererRef,
		SDL_Window* gWindowRef
	);
	
	// Engine References
	InputHandler& inputHandler;
	SubEmitEventManager& subEmitEventManager;
	Renderer& renderer;
	SDL_Event& eventObject;
	PlayerMovement playerMovement;

	// Window
	
	SDL_Window* gWindow;

	// Debug
	DebugOutput debugOutput;

	// Player
	Player player;

	void InitializeGameCode();
	void InPollCode(SDL_Event& eventObject);
	void InLoopCode();
	void InitializeLevel();


};


#endif 

