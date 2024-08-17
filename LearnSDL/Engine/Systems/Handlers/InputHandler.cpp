#include "InputHandler.h"

InputHandler::InputHandler() {
    // Constructor logic if needed
}

InputHandler::~InputHandler() {
    // Destructor logic if needed
}

void InputHandler::handleEvents(bool& quit, SDL_Surface*& currentSurface, SDL_Surface* surfaces[], int totalSurfaces) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN) {
            handleKeyPress(e.key.keysym.sym, currentSurface, surfaces, totalSurfaces);
        }
    }
}

void InputHandler::handleKeyPress(SDL_Keycode key, SDL_Surface*& currentSurface, SDL_Surface* surfaces[], int totalSurfaces) {
    switch (key) {
    case SDLK_UP:
        currentSurface = surfaces[1]; // Assuming surfaces[1] is the UP surface
        break;
    case SDLK_DOWN:
        currentSurface = surfaces[2]; // Assuming surfaces[2] is the DOWN surface
        break;
    case SDLK_LEFT:
        currentSurface = surfaces[3]; // Assuming surfaces[3] is the LEFT surface
        break;
    case SDLK_RIGHT:
        currentSurface = surfaces[4]; // Assuming surfaces[4] is the RIGHT surface
        break;
    default:
        currentSurface = surfaces[0]; // Default surface
        break;
    }
}