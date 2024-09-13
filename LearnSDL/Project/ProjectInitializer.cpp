
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
	playerMovementInput(),
	gWindow(gWindowRef),
	playerV2(),
	//player()
	regularBox(glm::vec3(0.55f, 0.80f, 0.0f))
	//regularBox2(glm::vec3(0.75f, 0.55f, 0.0f)),
	//regularBox3(glm::vec3(0.55f, 0.30f, 0.0f))
{

}

void ProjectInitializer::InitializeGameCode()
{
	//subEmitEventManager.registerListener("EnemyKilled", randomCode );
	//inputHandler.setAction(SDLK_UP, [this]() { subEmitEventManager.emit("EnemyKilled", eventObject); });
	//inputHandler.setAction(SDLK_RIGHT, [this]() { debugOutput.outputYellowText("NONE SET"); });
	//playerMovement.OnInit();
	// Example position
	/*glm::vec3 boxPosition(0.0f, 0.0f, 0.0f);
	regularBox = RegularBox(boxPosition);*/
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
	KeyPress movementX = playerMovementInput.currentXMovementState;
	KeyPress movementY = playerMovementInput.currentYMovementState;

	//player.Tick();
	//regularBox.Tick();
	//regularBox2.Tick();
	//regularBox3.Tick();
	playerV2.Tick();

	//player.DrawSelf();
	regularBox.DrawSelf();
	//regularBox2.DrawSelf();
	//regularBox3.DrawSelf();
	playerV2.DrawSelf();

	//renderer.drawer.MoveSquare(movementX, movementY);
}

void ProjectInitializer::InitializeLevel()
{
	
}



