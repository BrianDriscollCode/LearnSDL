
#include "ProjectInitializer.h"
#include "./Game/GameTest.h"

ProjectInitializer::ProjectInitializer(InputHandler& inputHandlerRef, SubEmitEventManager& subEmitEventManagerRef, SDL_Event& eventObjectRef)
	: inputHandler(inputHandlerRef), subEmitEventManager(subEmitEventManagerRef), eventObject(eventObjectRef)
{

}

void ProjectInitializer::randomCode(const SDL_Event& event)
{
	printf("ProjectInitializer::RunEvent::EnemyKilled");
}

void ProjectInitializer::gameCode()
{
	subEmitEventManager.registerListener("EnemyKilled", randomCode );
	//inputHandler.setAction(SDLK_UP, [this]() { subEmitEventManager.emit("EnemyKilled", eventObject); });
}


