#include <functional>
#include <vector>
#include <unordered_map>
#include <SDL.h>

#include "EventManager.h"

using EventCallback = std::function<void(const SDL_Event&)>;

EventManager::EventManager()
{
    
}

    std::unordered_map<Uint32, std::vector<EventCallback>> listeners;

    void EventManager::registerListener(Uint32 eventType, EventCallback callback) {
        listeners[eventType].push_back(callback);
    }

    void EventManager::processEvent(const SDL_Event& event) {

        auto it = listeners.find(event.type);
        if (it != listeners.end()) {
            for (auto& callback : it->second) {
                callback(event);
            }
        }
    }

    void EventManager::processEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            processEvent(event);
        }
    }



