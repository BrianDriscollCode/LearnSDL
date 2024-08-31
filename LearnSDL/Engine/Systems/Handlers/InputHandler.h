#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>
#include <functional>
#include <unordered_map>
#include "../Engine/Debug/DebugOutput.h"

class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    void handleEvents(SDL_Event eventObject);

    void setAction(SDL_Keycode key, std::function<void()> action);
    void setKeyUpAction(SDL_Keycode key, std::function<void()> action);

private:
    void handleKeyDown(SDL_Keycode key);
    void handleKeyUp(SDL_Keycode key);

    std::unordered_map<SDL_Keycode, std::function<void()>> keyDownActions;
    std::unordered_map<SDL_Keycode, std::function<void()>> keyUpActions;

    // Debug output (assuming it's defined elsewhere)
    DebugOutput debugOutput;
};

#endif // INPUTHANDLER_H