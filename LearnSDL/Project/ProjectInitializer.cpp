
#include "ProjectInitializer.h"


ProjectInitializer::ProjectInitializer(
	InputHandler& inputHandlerRef,
	SubEmitEventManager& subEmitEventManagerRef,
	SDL_Event& eventObjectRef,
	Renderer& rendererRef
)
	: inputHandler(inputHandlerRef),
	subEmitEventManager(subEmitEventManagerRef),
	eventObject(eventObjectRef),
	renderer(rendererRef),
	debugOutput(true),
	playerMovement(inputHandlerRef)
{

}

void ProjectInitializer::InitializeGameCode()
{
	//subEmitEventManager.registerListener("EnemyKilled", randomCode );
	//inputHandler.setAction(SDLK_UP, [this]() { subEmitEventManager.emit("EnemyKilled", eventObject); });
	//inputHandler.setAction(SDLK_RIGHT, [this]() { debugOutput.outputYellowText("NONE SET"); });
	//playerMovement.OnInit();
}

void ProjectInitializer::InLoopCode(SDL_Event& eventObject)
{
	playerMovement.MoveInput(eventObject);
}


