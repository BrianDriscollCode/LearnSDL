#ifndef SHAPELIBRARY_H
#define SHAPELIBRARY_H

#include <SDL_opengl.h>

class ShapeLibrary
{
public:
    GLfloat squareVertices[12] = {
        -0.1f,  0.1f, 0.0f,  // Top-left
        -0.1f, -0.1f, 0.0f,  // Bottom-left
         0.1f, -0.1f, 0.0f,  // Bottom-right
         0.1f,  0.1f, 0.0f   // Top-right
    };

    GLuint squareIndices[6] = {
        0, 1, 2,  // First triangle
        2, 3, 0   // Second triangle
    };
};

#endif // !SHAPELIBRARY_H
