#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

// Handlers
#include "./Handlers/InputHandler.h"
#include "./Handlers/WindowHandler.h"

// Loaders
#include "./Loaders/MediaLoader.h"
#include "./Loaders/SurfaceLoader.h"

//Managers
#include "./Managers/CallbackEventManager.h"
#include "./Managers/SubEmitEventManager.h"
#include "./Entity/EntityManager.h"


class SystemManager
{
public: 

	SystemManager();

	void initiateSystems();
	
	// Handlers
	InputHandler inputHandler;
	WindowHandler windowHandler;

	// Loaders
	//MediaLoader mediaLoader;  - Not yet created
	SurfaceLoader surfaceLoader;

	// Managers
	CallbackEventManager callbackEventManager;
	SubEmitEventManager subEmitEventManager;
	EntityManager entityManager;
	
};

#endif