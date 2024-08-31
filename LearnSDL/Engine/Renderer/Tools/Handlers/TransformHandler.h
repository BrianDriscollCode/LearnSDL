#ifndef TRANSFORMHANDLER_H
#define TRANSFORMHANDLER_H

#include "SDL_opengl.h"

// Utilities
#include "../Engine//Utilities/Enum/KeyPress.h"
#include "../Engine/Debug/DebugOutput.h"

class TransformHandler
{
public:
    TransformHandler();
    DebugOutput debugOutput;

    // Method to set initial vertices
    void SetInitialVertices(const GLfloat initialVertices[12]);

    // Method to move the object and update vertices
    void MoveObject(KeyPress xDirection, KeyPress yDirection);

    // Method to get the vertices array
    const GLfloat* GetVertices() const;

private:
    // Array to store vertices
    GLfloat vertices[12];

    // Speed constant
    static constexpr GLfloat SPEED = 0.01f;
};

#endif // TRANSFORMHANDLER_H