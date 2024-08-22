
#include "TestBed.h"
#include "SystemManager.h"
#include "Managers/SubEmitEventManager.h"


TestBed::TestBed(SystemManager& systemManager) : systemManager(systemManager) {};

void TestBed::printLife(const SDL_Event& event)
{
	printf("Life is here - printLife::function\n");
}

void TestBed::testEmit()
{
	SubEmitEventManager& subEmitEventManager = systemManager.subEmitEventManager;


	// Registering member function using a lambda function
	subEmitEventManager.registerListener("EnemyKilled", [this](const SDL_Event& event) {
		this->printLife(event);
	});
	
	
}