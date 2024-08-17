#include <SDL.h>
#include <stdio.h>
#include <string>

#include "SurfaceLoader.h"

SurfaceLoader::SurfaceLoader()
{
    //init
}

    SDL_Surface* SurfaceLoader::loadSurface(const std::string& path, SDL_Surface* gScreenSurface)
    {
        // Final optimized image
        SDL_Surface* optimizedSurface = NULL;

        // Load image at specified path
        SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

        if (loadedSurface == NULL)
        {
            printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
            if (optimizedSurface == NULL)
            {
                printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
            }

            SDL_FreeSurface(loadedSurface);
        }

        return optimizedSurface;
    }

    // Additional functions can be added directly here