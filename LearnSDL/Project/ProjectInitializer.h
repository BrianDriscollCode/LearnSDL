#ifndef PROJECTINITIALIZER_H
#define PROJECTINITIALIZER_H


// External Libraries
#include <SDL.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

// Systems
#include "../Engine/Systems/Handlers/InputHandler.h"
#include "../Engine/Systems/Managers/SubEmitEventManager.h"

// Renderer
#include "../Engine/Renderer/Renderer.h"

// Utilities
#include "../Engine/Utilities/Enum/KeyPress.h"

// Game Scripts
#include "../Project/Game/Player/PlayerMovementInput.h"
#include "../Project/Game/Player/Player.h"
#include "../Project/Game/Player/RegularBox.h"

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
	PlayerMovementInput playerMovementInput;

	// Window
	
	SDL_Window* gWindow;

	// Debug
	DebugOutput debugOutput;

	// Player
	Player player;
	

	// Objects
	RegularBox regularBox;
	RegularBox regularBox2;
	RegularBox regularBox3;
	RegularBox regularBox4;

	void InitializeGameCode();
	void InPollCode(SDL_Event& eventObject);
	void InLoopCode();
	void InitializeLevel();


};


#endif 

