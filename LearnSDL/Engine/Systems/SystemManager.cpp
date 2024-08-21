
#include "SystemManager.h"

SystemManager::SystemManager()
{
	// Handlers
	InputHandler inputHandler;
	WindowHandler windowHandler;

	// Loaders
	//MediaLoader mediaLoader;  - Not yet created
	SurfaceLoader surfaceLoader;

	// Managers
	CallbackEventManager callbackEventManager;
}
