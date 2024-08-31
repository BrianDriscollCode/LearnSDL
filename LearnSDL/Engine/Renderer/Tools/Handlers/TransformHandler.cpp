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
void TransformHandler::MoveObject(KeyPress xDirection, KeyPress yDirection)
{
    int counter = 1;
    int speedXTransform = 1;
    int speedYTransform = 1;
    bool axisX = false;
    bool axisY = false;
    

    switch (xDirection)
    {
        case LEFT:
            speedXTransform = -1;
            axisX = true;
            debugOutput.outputYellowText("LEFT");
            break;
        case RIGHT:
            speedXTransform = 1;
            axisX = true;
            debugOutput.outputYellowText("RIGHT");
            break;
    }

    switch (yDirection)
    {
        case UP:
            speedYTransform = 1;
            axisY = true;
            debugOutput.outputRedText("UP");
            break;
        case DOWN:
            speedYTransform = -1;
            axisY = true;
            debugOutput.outputRedText("DOWN");
            break;
    }

    // Targets vertexes for changing position

    
        for (int i = 0; i < 12; ++i)
        {
            counter += 1;
            
            // 
            if (counter % 3 != 0 && axisX == true)
            {
                vertices[i] += SPEED * speedXTransform;
            }

            if (counter % 3 == 0 && axisY == true)
            {
                vertices[i] += SPEED * speedYTransform;
            }
        }
    
   
    
}

// Method to get the vertices array
const GLfloat* TransformHandler::GetVertices() const
{
    return vertices;
}