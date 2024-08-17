#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>

class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    // Poll events and handle them
    void handleEvents(bool& quit, SDL_Surface*& currentSurface, SDL_Surface* surfaces[], int totalSurfaces);

private:
    void handleKeyPress(SDL_Keycode key, SDL_Surface*& currentSurface, SDL_Surface* surfaces[], int totalSurfaces);
};

#endif