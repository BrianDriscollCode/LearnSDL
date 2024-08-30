#ifndef DRAWER_H
#define DRAWER_H

#include <GL/glew.h>
#include <SDL_opengl.h>
#include <SDL.h>

#include "../Engine/Debug/DebugOutput.h"
#include "../Tools/TransformHandler.h"

// Utilities

#include "../Engine/Utilities/Enum/KeyPress.h"

class Drawer
{
public:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    float offsetX;
    float offsetY;
    DebugOutput debugOutput;
    TransformHandler transformHandler;

    Drawer(bool activate);

    void initializeDrawer(GLfloat vertices[], GLuint indices[], int verticesSize, int indicesSize);

    void SetAttributePointers();

    void Draw(SDL_Window* gWindow);

    void MoveSquare(KeyPress direction);

    void DeleteDrawer();
};

#endif