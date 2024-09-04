#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

#include "../Engine/Systems/Handlers/InputHandler.h"
#include "../Engine/Utilities/Enum/KeyPress.h"

#include "../Engine/Debug/DebugOutput.h"

class PlayerMovement
{
public:
	PlayerMovement(InputHandler& inputHandlerRef);
	InputHandler& inputHandler;
	DebugOutput debugOutput;

	void MoveInput(SDL_Event& eventObject);

	KeyPress currentXMovementState = NONE;
	KeyPress currentYMovementState = NONE;
};

#endif