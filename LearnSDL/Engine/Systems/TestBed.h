#ifndef TESTBED_H
#define TESTBED_H

#include <SDL.h>
#include "SystemManager.h"

class TestBed
{
public:
	TestBed(SystemManager& systemManager);
	void printLife(const SDL_Event& event);
	void testEmit();
	

private:
	SystemManager& systemManager;
};

#endif