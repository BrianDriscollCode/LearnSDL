#include "InputHandler.h"
#include <cstdio>

InputHandler::InputHandler()
    : debugOutput(true) // Assuming you have a DebugOutput instance or similar
{
    // Constructor logic if needed
}

InputHandler::~InputHandler() {
    // Destructor logic if needed
}

void InputHandler::handleEvents(SDL_Event eventObject) {
    if (eventObject.type == SDL_QUIT) {
        exit(0);
    }
    if (eventObject.type == SDL_KEYDOWN) {
        handleKeyDown(eventObject.key.keysym.sym);
        //debugOutput.outputYellowText("KEYDOWN");
        
    }
    else if (eventObject.type == SDL_KEYUP) {
        handleKeyUp(eventObject.key.keysym.sym);
        //debugOutput.outputYellowText("KEYUP");
    }
}

void InputHandler::handleKeyDown(SDL_Keycode key) {
    auto it = keyDownActions.find(key);
    if (it != keyDownActions.end()) {
        it->second(); // Call the action for key down
    }
    else {
        //printf("Key down default action\n"); // Default action if key not found
    }
}

void InputHandler::handleKeyUp(SDL_Keycode key) {
    auto it = keyUpActions.find(key);
    if (it != keyUpActions.end()) {
        it->second(); // Call the action for key up
    }
    else {
        //printf("Key up default action\n"); // Default action if key not found
    }
}

void InputHandler::setAction(SDL_Keycode key, std::function<void()> action) {
    keyDownActions[key] = action;
    //debugOutput.outputYellowText("INPUTHANDLER::SetActionReceived");
}

void InputHandler::setKeyUpAction(SDL_Keycode key, std::function<void()> action) {
    keyUpActions[key] = action;
}