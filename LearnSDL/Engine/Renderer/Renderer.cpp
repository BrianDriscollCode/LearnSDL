#include "Renderer.h"

// Libraries
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

// Debug
#include "../Debug/DebugOutput.h"

// Render Tools
#include "./Tools/Drawer.h"


Renderer::Renderer()
	: debugOutput(true), drawer(true)
{
    // Initialize member variables
    GLfloat tempVertices[] = {
        -0.1f,  0.1f, 0.0f,  // Top-left
        -0.1f, -0.1f, 0.0f,  // Bottom-left
         0.1f, -0.1f, 0.0f,  // Bottom-right
         0.1f,  0.1f, 0.0f   // Top-right
    };

    GLuint tempIndices[] = {
        0, 1, 2,  // First triangle
        2, 3, 0   // Second triangle
    };

    // Copy temp arrays to member variables
    std::copy(std::begin(tempVertices), std::end(tempVertices), std::begin(vertices));
    std::copy(std::begin(tempIndices), std::end(tempIndices), std::begin(indices));

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

void Renderer::StartRenderer()
{  
    drawer.initializeDrawer(vertices, indices, sizeof(vertices), sizeof(indices));
    drawer.SetAttributePointers();

    shader = std::make_unique<Shader>("./Engine/Renderer/Resources/BasicSquare.vert", "./Engine/Renderer/Resources/BasicSquare.frag");
    
    debugOutput.outputGreenText("Start Render");
    debugOutput.outputGreenText("**SUCCESS**::INITIALIZERENDERER::BUFFERSLOADED::[Engine/Renderer/InitializeRenderer.h]");
}

void Renderer::TerminateRenderer()
{
    drawer.DeleteDrawer();

    if (shader)
    {
        glDeleteProgram(shader->getProgram());
    }

    debugOutput.outputGreenText("**SUCCESS**::TERMINATERENDERER::CLOSING::[Engine/Renderer/InitializeRenderer.h]");
}

void Renderer::RenderScene(SDL_Window* gWindow)
{
    if (shader)
    {
        shader->use();
    }
    drawer.Draw(gWindow);
}