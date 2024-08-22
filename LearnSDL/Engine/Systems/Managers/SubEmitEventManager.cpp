
#include "SubEmitEventManager.h"
#include <iostream>
#include <string>

SubEmitEventManager::SubEmitEventManager() {}


// Events are registered here. Instead of emitting and thinking all files that register
// "hear" this emit, instead, all the registered listeners filed for that type of event
// get called
void SubEmitEventManager::registerListener(const EventType& eventType, EventCallback callback)
{
	printf("eventType registered: %s\n", eventType.c_str());
	listeners[eventType].push_back(callback);
}

void SubEmitEventManager::emit(const EventType& eventType, const SDL_Event& event)
{
	auto it = listeners.find(eventType);
	if (it != listeners.end())
	{
		for (auto& callback : it->second)
		{
			callback(event);
		}
	}
}
