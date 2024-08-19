#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>
#include <unordered_map>
#include <functional>

class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    // Poll events and handle them
    void handleEvents(SDL_Event eventObject);

    // relook to understand
    void setAction(SDL_Keycode key, std::function<void()> action);

private:
    void handleKeyPress(SDL_Keycode key);

    // relook to understand
    std::unordered_map<SDL_Keycode, std::function<void()>> keyActions;
    
};

#endif