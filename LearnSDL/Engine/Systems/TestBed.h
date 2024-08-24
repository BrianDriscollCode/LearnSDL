#ifndef TESTBED_H
#define TESTBED_H

#include <SDL.h>
#include "SystemManager.h"
#include <functional>

class TestBed
{
public:
	TestBed(SystemManager& systemManager);
	void printLife();
	void testEmit();

	

private:
	SystemManager& systemManager;
};

#endif