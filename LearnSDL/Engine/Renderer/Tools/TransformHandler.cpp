#include "TransformHandler.h"

// Default constructor
TransformHandler::TransformHandler()
    : debugOutput(true)
{
    // Initialize vertices with default values (optional)
    for (int i = 0; i < 12; ++i)
    {
        vertices[i] = 0.0f;
    }
}

// Method to set initial vertices
void TransformHandler::SetInitialVertices(const GLfloat initialVertices[12])
{
    for (int i = 0; i < 12; ++i)
    {
        vertices[i] = initialVertices[i];  // Set values instead of adding
    }
}

// Method to move the object and update vertices
void TransformHandler::MoveObject(KeyPress direction)
{
    int counter = 1;
    int speedTransform = 1;
    bool axisX = false;
    bool axisY = false;
    

    switch (direction)
    {
        case LEFT:
            speedTransform = -1;
            axisX = true;
            debugOutput.outputYellowText("PRESS LEFT");
            break;
        case RIGHT:
            speedTransform = 1;
            axisX = true;
            debugOutput.outputYellowText("PRESS RIGHT");
            break;
        case DOWN: 
            speedTransform = -1;
            axisY = true;
            debugOutput.outputYellowText("PRESS DOWN");
            break;
        case UP:
            speedTransform = 1;
            axisY = true;
            debugOutput.outputYellowText("PRESS UP");
            break;
    }

    for (int i = 0; i < 12; ++i)
    {
        counter += 1;
        if (counter % 3 != 0 && axisX == true)
        {
            vertices[i] += SPEED * speedTransform;
        }
        
        if (counter % 3 == 0 && axisY == true)
        {
            vertices[i] += SPEED * speedTransform;
        }
    }
}

// Method to get the vertices array
const GLfloat* TransformHandler::GetVertices() const
{
    return vertices;
}