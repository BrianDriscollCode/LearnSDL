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

    // Member variables for vertices and indices
    GLfloat vertices[12];
    GLuint indices[6];

    // Constructor that initializes VAO, VBO, and shaderProgram
    Renderer();

    void StartRenderer();
    void TerminateRenderer();
    void RenderScene(SDL_Window* gWindow);
};

#endif