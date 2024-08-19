#include "InputHandler.h"
#include <cstdio>

InputHandler::InputHandler() {
    // Constructor logic if needed
}

InputHandler::~InputHandler() {
    // Destructor logic if needed
}


void InputHandler::handleEvents(SDL_Event eventObject) {

    if (eventObject.type == SDL_QUIT) {
        // do nothing
    }
    else if (eventObject.type == SDL_KEYDOWN) {
        handleKeyPress(eventObject.key.keysym.sym);
    }

}

void InputHandler::handleKeyPress(SDL_Keycode key) {
    // Find the action associated with the key and execute it
    auto it = keyActions.find(key);
    if (it != keyActions.end()) {
        it->second(); // Call the action
    }
    else {
        printf("default"); // Default action if key not found
    }
}

// Relook at this to understand
void InputHandler::setAction(SDL_Keycode key, std::function<void()> action) {
    keyActions[key] = action;
}

//void InputHandler::handleKeyPress(SDL_Keycode key, SDL_Surface*& currentSurface, SDL_Surface* surfaces[], int totalSurfaces) {
//    switch (key) {
//    case SDLK_UP:
//        currentSurface = surfaces[1]; // Assuming surfaces[1] is the UP surface
//        break;
//    case SDLK_DOWN:
//        currentSurface = surfaces[2]; // Assuming surfaces[2] is the DOWN surface
//        break;
//    case SDLK_LEFT:
//        currentSurface = surfaces[3]; // Assuming surfaces[3] is the LEFT surface
//        break;
//    case SDLK_RIGHT:
//        currentSurface = surfaces[4]; // Assuming surfaces[4] is the RIGHT surface
//        break;
//    default:
//        currentSurface = surfaces[0]; // Default surface
//        break;
//    }
//}