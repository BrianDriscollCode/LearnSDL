#ifndef INITIALIZERENDERER_H
#define INITIALIZERENDERER_H

#include <GL/glew.h>
#include <SDL_opengl.h>

// Debug
#include "../Debug/DebugOutput.h"

// Render Tools
#include "./Tools/Drawer.h"

// Shader Tools
#include "./Shaders/Shader.h"

class Renderer {
public:
    DebugOutput debugOutput;
    Drawer drawer;
    std::unique_ptr<Shader> shader;

    // Constructor that initializes VAO, VBO, and shaderProgram
    Renderer(SDL_Window* gWindowRef);

    void Init();
    void TerminateRenderer();
};

#endif