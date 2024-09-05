#include "PlayerMovement.h"

PlayerMovement::PlayerMovement()
    : debugOutput(true)
{
}

void PlayerMovement::MoveInput()
{

    // Get Keyboard input
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    // Set Movement States for x and y directions
    if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        currentXMovementState = LEFT;
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        currentXMovementState = RIGHT;
    }
    else
    {
        currentXMovementState = NONE;
    }
    
    if (currentKeyStates[SDL_SCANCODE_UP]) {
        currentYMovementState = UP;
    }
    else if (currentKeyStates[SDL_SCANCODE_DOWN]) {
        currentYMovementState = DOWN;
    }
    else {
        currentYMovementState = NONE;
    }

}
