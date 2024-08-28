#ifndef PROJECTINITIALIZER_H
#define PROJECTINITIALIZER_H

#include "../Engine/Systems/Handlers/InputHandler.h"
#include "../Engine/Systems/Managers/SubEmitEventManager.h"
#include <SDL.h>

class ProjectInitializer
{
public:
	ProjectInitializer(InputHandler& inputHandlerRef, SubEmitEventManager& subEmitEventManagerRef, SDL_Event& eventObjectRef);
	InputHandler& inputHandler;
	SubEmitEventManager& subEmitEventManager;
	SDL_Event& eventObject;

	static void randomCode(const SDL_Event& event);
	void gameCode();


};


#endif 

