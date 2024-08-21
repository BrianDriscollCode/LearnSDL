#ifndef SUBEMITEVENTMANAGER_H
#define SUBEMITEVENTMANAGER_H

#include <functional>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include <SDL.h>

using EventCallback = std::function<void(const SDL_Event&)>;

class SubEmitEventManager
{
public:
	SubEmitEventManager();

	std::map<std::string, int> EventTypeMap;

	void registerListener(std::map<std::string, int> eventType, EventCallback callback);

	void emit();

};


#endif // !SUBEMITEVENTMANAGER
