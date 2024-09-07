#include "Renderer.h"

// Libraries
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

// Debug
#include "../Debug/DebugOutput.h"

// Render Tools
#include "./Tools/Drawer.h"


Renderer::Renderer(SDL_Window* gWindowRef)
	: debugOutput(true), drawer(true, gWindowRef), gWindow(gWindowRef)
{
    // Set the attributes for OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Use Vsync
    if (SDL_GL_SetSwapInterval(1) < 0)
    {
        printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
    }
}

void Renderer::Init()
{  
    drawer.initializeSquareVAO();
    //shader = std::make_unique<Shader>("./Engine/Renderer/Shaders/Resources/BasicSquare.vert", "./Engine/Renderer/Shaders/Resources/BasicSquare.frag");
    
    debugOutput.outputGreenText("Start Render");
    debugOutput.outputGreenText("**SUCCESS**::INITIALIZERENDERER::BUFFERSLOADED::[Engine/Renderer/InitializeRenderer.h]");
}

void Renderer::TerminateRenderer()
{
    drawer.DeleteDrawer();

    debugOutput.outputGreenText("**SUCCESS**::TERMINATERENDERER::CLOSING::[Engine/Renderer/InitializeRenderer.h]");
}
