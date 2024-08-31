//bool loadMedia()
//{
//
//	SurfaceLoader& surfaceLoader = systemManager.surfaceLoader;
//	//Loading success flag
//	bool success = true;
//
//	//Load default surface
//	gKeyPressSurfaces[ DEFAULT ] = surfaceLoader.loadSurface( "Assets/keys/press.bmp", gScreenSurface );
//	
//	if( gKeyPressSurfaces[ DEFAULT ] == NULL )
//	{
//		printf( "Failed to load default image!\n" );
//		success = false;
//	}
//	else
//	{
//		printf("Image Loaded Correctly!\n");
//	}
//
//	//Load up surface
//	gKeyPressSurfaces[ UP ] = surfaceLoader.loadSurface( "Assets/keys/up.bmp", gScreenSurface );
//	
//	if( gKeyPressSurfaces[ UP ] == NULL )
//	{
//		printf( "Failed to load up image!\n" );
//		success = false;
//	}
//	else
//	{
//		printf("Image Loaded Correctly!\n");
//	}
//
//	//Load down surface
//	gKeyPressSurfaces[ DOWN ] = surfaceLoader.loadSurface( "Assets/keys/down.bmp", gScreenSurface );
//	
//	if( gKeyPressSurfaces[ DOWN ] == NULL )
//	{
//		printf( "Failed to load down image!\n" );
//		success = false;
//	}
//	else
//	{
//		printf("Image Loaded Correctly!\n");
//	}
//
//	//Load left surface
//	gKeyPressSurfaces[ LEFT ] = surfaceLoader.loadSurface( "Assets/keys/left.bmp", gScreenSurface );
//	
//	if( gKeyPressSurfaces[ LEFT ] == NULL )
//	{
//		printf( "Failed to load left image!\n" );
//		success = false;
//	}
//
//	//Load right surface
//	gKeyPressSurfaces[ RIGHT ] = surfaceLoader.loadSurface( "Assets/keys/right.bmp", gScreenSurface );
//	
//	if( gKeyPressSurfaces[ RIGHT ] == NULL )
//	{
//		printf( "Failed to load right image!\n" );
//		success = false;
//	}
//	else
//	{
//		printf("Image Loaded Correctly!\n");
//	}
//
//	return success;
//}

//// Set up events
		///*callbackEventManager.registerListener(SDL_KEYDOWN, [](const SDL_Event& event) {
		//	if (event.key.keysym.sym == SDLK_UP)
		//	{
		//		printf("up key event!\n");
		//	}
		//});*/


		//subEmitEventManager.registerListener("PlayerSaved", playerAlive);

		//testBed.testEmit();

		//// Assign actions
		//inputHandler.setAction(SDLK_UP, [eventObject, &subEmitEventManager]() { subEmitEventManager.emit("EnemyKilled", eventObject); });
		//inputHandler.setAction(SDLK_DOWN, [eventObject, &subEmitEventManager]() { subEmitEventManager.emit("PlayerSaved", eventObject); });
		//inputHandler.setAction(SDLK_LEFT, []() { printf("Left key pressed\n"); });
		//inputHandler.setAction(SDLK_RIGHT, []() { printf("Right key pressed\n"); });