
#include "ProjectInitializer.h"


ProjectInitializer::ProjectInitializer(
	InputHandler& inputHandlerRef,
	SubEmitEventManager& subEmitEventManagerRef,
	SDL_Event& eventObjectRef,
	Renderer& rendererRef,
	SDL_Window* gWindowRef
)
	:inputHandler(inputHandlerRef),
	subEmitEventManager(subEmitEventManagerRef),
	eventObject(eventObjectRef),
	renderer(rendererRef),
	debugOutput(true),
	playerMovement(),
	gWindow(gWindowRef)
{

}

void ProjectInitializer::InitializeGameCode()
{
	//subEmitEventManager.registerListener("EnemyKilled", randomCode );
	//inputHandler.setAction(SDLK_UP, [this]() { subEmitEventManager.emit("EnemyKilled", eventObject); });
	//inputHandler.setAction(SDLK_RIGHT, [this]() { debugOutput.outputYellowText("NONE SET"); });
	//playerMovement.OnInit();
}

void ProjectInitializer::InPollCode(SDL_Event& eventObject)
{
	//Entity player;
	//playerMovement.MoveInput(eventObject);
	//renderer.drawer.DrawSquare(gWindow, player);
	// NEED TO FIGURE OUT
	// HOW TO GET SCRIPT TO:
	//	1. has ref to player
	//  2. Can run drawsquare, need hook that has ref to gWindow
	
}

void ProjectInitializer::InLoopCode()
{
	KeyPress movementX = playerMovement.currentXMovementState;
	KeyPress movementY = playerMovement.currentYMovementState;

	player.Tick();
	//renderer.drawer.MoveSquare(movementX, movementY);
}

void ProjectInitializer::InitializeLevel()
{
	
}



