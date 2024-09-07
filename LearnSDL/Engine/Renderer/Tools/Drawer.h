#ifndef DRAWER_H
#define DRAWER_H

#include <GL/glew.h>
#include <SDL_opengl.h>
#include <SDL.h>

#include "../Engine/Debug/DebugOutput.h"

// Systems

#include "../Engine/Entity/Entity.h"

// Utilities

#include "../Engine/Utilities/Enum/KeyPress.h"

// GLM

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

// Shader Tools
#include "../Shaders/Shader.h"

class Drawer
{
public:
    GLuint squareVAO;
    GLuint VBO;
    GLuint EBO;
    float offsetX;
    float offsetY;
    DebugOutput debugOutput;
    SDL_Window* gWindow;
    

    std::unique_ptr<Shader> squareShader;

    Drawer(bool activate, SDL_Window* gWindow);

    void initializeSquareVAO();

    void DrawSquare(SDL_Window* gWindow, Entity player);

    void EndDraw();

    void DeleteDrawer();
};

#endif