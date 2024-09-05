#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

// Engine Systems
#include "../Engine/Utilities/Enum/KeyPress.h"
#include "../Engine/Debug/DebugOutput.h"

// References

//#include "../Engine/Systems/Helper/ReferenceHelper.h"

#include <SDL.h>

class PlayerMovement
{
public:
	PlayerMovement();
	DebugOutput debugOutput;

	void MoveInput();

	KeyPress currentXMovementState = NONE;
	KeyPress currentYMovementState = NONE;
};

#endif