
#include "TestBed.h"
#include "SystemManager.h"
#include "Managers/SubEmitEventManager.h"


TestBed::TestBed(SystemManager& systemManager) : systemManager(systemManager) 
{
};

void TestBed::printLife()
{
	printf("Life is here - printLife::function\n");
}

void TestBed::testEmit()
{
	SubEmitEventManager& subEmitEventManager = systemManager.subEmitEventManager;

	// Registering member function using a lambda function
	
	// (param1: eventType, param2: event)
	// param1 - whenever this is called in the application, this event will run
	// param2 - binds an event, to the context of "this" object, to call back the provided logic
	subEmitEventManager.registerListener("EnemyKilled", [this](const SDL_Event& event) {
		this->printLife();
	});
	
	
}