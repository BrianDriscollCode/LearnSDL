#ifndef SURFACELOADER_H
#define SURFACELOADER_H

#include <SDL.h>
#include <string>

class SurfaceLoader
{
public:
 
    // Constructor
    SurfaceLoader();

    // Function to load and optimize a surface
    SDL_Surface* loadSurface(const std::string& path, SDL_Surface* gScreenSurface);
};

#endif // SURFACELOADER_H