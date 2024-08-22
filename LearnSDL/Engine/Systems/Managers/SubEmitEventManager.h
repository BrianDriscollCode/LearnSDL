#ifndef SUBEMITEVENTMANAGER_H
#define SUBEMITEVENTMANAGER_H

#include <functional>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include <SDL.h>

using EventType = std::string;

using EventCallback = std::function<void(const SDL_Event&)>;


class SubEmitEventManager
{
public:
	SubEmitEventManager();

	void registerListener(const EventType& eventType, EventCallback callback);

	void emit(const EventType& eventType, const SDL_Event& event);

private:

	std::unordered_map<EventType, std::vector<EventCallback>> listeners;
};


#endif // !SUBEMITEVENTMANAGER
