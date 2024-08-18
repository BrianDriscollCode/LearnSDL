#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <functional>
#include <vector>
#include <unordered_map>
#include <SDL.h>

using EventCallback = std::function<void(const SDL_Event&)>;

class EventManager
{
public:

	EventManager();

	void registerListener(Uint32 eventType, EventCallback callback);

	void processEvent(const SDL_Event &event);
	
	void processEvents();

private:
	std::unordered_map<Uint32, std::vector<EventCallback>> listeners;
};



#endif