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

// Utilities
#include "../Engine/Debug/DebugOutput.h"

class ProjectInitializer
{
public:
	ProjectInitializer(InputHandler& inputHandlerRef, SubEmitEventManager& subEmitEventManagerRef, SDL_Event& eventObjectRef, Renderer& rendererRef);
	
	// Engine References
	InputHandler& inputHandler;
	SubEmitEventManager& subEmitEventManager;
	Renderer& renderer;
	SDL_Event& eventObject;
	PlayerMovement playerMovement;

	// Debug
	DebugOutput debugOutput;

	void InitializeGameCode();
	void InLoopCode(SDL_Event& eventObject);


};


#endif 

