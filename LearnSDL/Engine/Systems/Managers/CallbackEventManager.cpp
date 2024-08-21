#include <functional>
#include <vector>
#include <unordered_map>
#include <SDL.h>

#include "CallbackEventManager.h"

using EventCallback = std::function<void(const SDL_Event&)>;

CallbackEventManager::CallbackEventManager()
{
    
}

    std::unordered_map<Uint32, std::vector<EventCallback>> listeners;
    bool debugMode = true;

    void CallbackEventManager::registerListener(Uint32 eventType, EventCallback callback) {
        listeners[eventType].push_back(callback);
    }

    void CallbackEventManager::processEvent(const SDL_Event& event) {

        auto it = listeners.find(event.type);
        if (it != listeners.end()) {
            for (auto& callback : it->second) {
                callback(event);
            }
        }
    }

    void CallbackEventManager::processEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            processEvent(event);
        }
    }

    std::unordered_map<Uint32, std::vector<EventCallback>>& CallbackEventManager::getListenersReference()
    {
        return listeners;
    }



