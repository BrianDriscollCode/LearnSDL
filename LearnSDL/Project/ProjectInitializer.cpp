
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
	player(),
	regularBox(glm::vec3(0.50f, 0.50f, 0.0f), glm::vec2(.20f, .20f)),
	regularBox2(glm::vec3(0.25f, 0.25f, 0.0f), glm::vec2(.20f, .20f)),
	regularBox3(glm::vec3(-0.50f, -0.50f, 0.0f), glm::vec2(.40f, .40f))
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

	player.Tick();
	regularBox.Tick();
	regularBox2.Tick();
	regularBox3.Tick();

	player.DrawSelf();
	regularBox.DrawSelf();
	regularBox2.DrawSelf();
	regularBox3.DrawSelf();

	//renderer.drawer.MoveSquare(movementX, movementY);
}

void ProjectInitializer::InitializeLevel()
{
	
}



