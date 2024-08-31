#include "PlayerMovement.h"

PlayerMovement::PlayerMovement(InputHandler& inputHandlerRef)
    : inputHandler(inputHandlerRef), debugOutput(true)
{
}

//void PlayerMovement::OnInit()
//{
//    bool isLeftPressed = false;
//    bool isRightPressed = false;
//    bool isUpPressed = false;
//    bool isDownPressed = false;
//
//
//
//    auto updateMovementState = [this, &isLeftPressed, &isRightPressed, &isUpPressed, &isDownPressed]() {
//        if (!isLeftPressed && !isRightPressed && !isUpPressed && !isDownPressed) {
//            currentMovementState = NONE;
//            //debugOutput.outputYellowText("NONE SET");
//        }
//    };
//
//    inputHandler.setAction(SDLK_LEFT, [this, &isLeftPressed, &updateMovementState]() {
//        isLeftPressed = true;
//        currentMovementState = LEFT;
//        //debugOutput.outputYellowText("LEFT SET");
//    });
//
//    inputHandler.setAction(SDLK_RIGHT, [this, &isRightPressed, &updateMovementState]() {
//        isRightPressed = true;
//        currentMovementState = RIGHT;
//        //debugOutput.outputYellowText("RIGHT SET");
//    });
//
//    inputHandler.setAction(SDLK_UP, [this, &isUpPressed, &updateMovementState]() {
//        isUpPressed = true;
//        currentMovementState = UP;
//        //debugOutput.outputYellowText("UP SET");
//    });
//
//    inputHandler.setAction(SDLK_DOWN, [this, &isDownPressed, &updateMovementState]() {
//        isDownPressed = true;
//        currentMovementState = DOWN;
//        //debugOutput.outputYellowText("DOWN SET");
//    });
//
//    // Handling key release events
//    inputHandler.setKeyUpAction(SDLK_LEFT, [this, &isLeftPressed, &updateMovementState]() {
//        isLeftPressed = false;
//        currentMovementState = NONE;
//        updateMovementState();
//        debugOutput.outputYellowText("KEYUP UP SET");
//    });
//
//    inputHandler.setKeyUpAction(SDLK_RIGHT, [this, &isRightPressed, &updateMovementState]() {
//        isRightPressed = false;
//        currentMovementState = NONE;
//        updateMovementState();
//        debugOutput.outputYellowText("KEYUP UP SET");
//    });
//
//    inputHandler.setKeyUpAction(SDLK_UP, [this, &isUpPressed, &updateMovementState]() {
//        isUpPressed = false;
//        currentMovementState = NONE;
//        updateMovementState();
//        debugOutput.outputYellowText("KEYUP UP SET");
//    });
//
//    inputHandler.setKeyUpAction(SDLK_DOWN, [this, &isDownPressed, &updateMovementState]() {
//        isDownPressed = false;
//        currentMovementState = NONE;
//        updateMovementState();
//        debugOutput.outputYellowText("KEYUP UP SET");
//    });
//
//    debugOutput.outputYellowText("PLAYER SCRIPT INITIATED");
//}

void PlayerMovement::MoveInput(SDL_Event& eventObject)
{

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
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

   /* if (eventObject.type == SDL_KEYDOWN) {
        debugOutput.outputGreenText("TEST");
        switch (eventObject.key.keysym.sym) 
        {
            case SDLK_LEFT: currentMovementState = LEFT; break;
            case SDLK_RIGHT: currentMovementState = RIGHT; break;
            case SDLK_UP: currentMovementState = UP; break;
            case SDLK_DOWN: currentMovementState = DOWN; break;
        }
    }

    if (eventObject.type == SDL_KEYUP) 
    {
        debugOutput.outputGreenText("TEST2");
        switch (eventObject.key.keysym.sym) 
        {
            case SDLK_LEFT: currentMovementState = NONE; break;
            case SDLK_RIGHT: currentMovementState = NONE; break;
            case SDLK_UP: currentMovementState = NONE; break;
            case SDLK_DOWN: currentMovementState = NONE; break;
        }
    }*/
}

KeyPress PlayerMovement::GetXMovementState()
{
    return currentXMovementState;
}

KeyPress PlayerMovement::GetYMovementState()
{
    return currentYMovementState;
}