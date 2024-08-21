#ifndef CALLBACKEVENTMANAGER_H
#define CALLBACKEVENTMANAGER_H

#include <functional>
#include <vector>
#include <unordered_map>
#include <SDL.h>

using EventCallback = std::function<void(const SDL_Event&)>;

class CallbackEventManager
{
public:

	CallbackEventManager();

	void registerListener(Uint32 eventType, EventCallback callback);

	void processEvent(const SDL_Event &event);
	
	void processEvents();

	std::unordered_map<Uint32, std::vector<EventCallback>>& getListenersReference();

private:
	std::unordered_map<Uint32, std::vector<EventCallback>> listeners;

	bool debugMode;
};



#endif