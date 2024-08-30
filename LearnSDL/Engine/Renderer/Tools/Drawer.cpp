
#include "Drawer.h"

#include "../Engine/Debug/DebugOutput.h"

Drawer::Drawer(bool activate)
	:debugOutput(true), VAO(0), VBO(0), EBO(0), offsetX(0.1f), offsetY(0.1f), transformHandler()
{
   
}

void Drawer::initializeDrawer(GLfloat vertices[], GLuint indices[], int verticesSize, int indicesSize)
{
    debugOutput.outputGreenText("Start Drawer");
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);


    transformHandler.SetInitialVertices(vertices);

    debugOutput.outputGreenText("**SUCCESS**::DRAWER::BUFFERS_LOADED::[Engine/Renderer/Drawer.h]");
}

void Drawer::SetAttributePointers()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind the VBO
    glBindVertexArray(0);

    debugOutput.outputGreenText("**SUCCESS**::DRAWER::AttributePointersSet::[Engine/Renderer/Drawer.h]");
}

void Drawer::Draw(SDL_Window* gWindow)
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    SDL_GL_SwapWindow(gWindow);
}

void Drawer::MoveSquare(KeyPress direction)
{

    //GLfloat updatedVertices[] =
    //{
    //    -0.1f + offsetX,  0.1f + offsetY, 0.0f,  // Top-left
    //    -0.1f + offsetX, -0.1f + offsetY, 0.0f,  // Bottom-left
    //     0.1f + offsetX, -0.1f + offsetY, 0.0f,  // Bottom-right
    //     0.1f + offsetX,  0.1f + offsetY, 0.0f   // Top-right
    //};

    //offsetX += offsetX;
   // offsetY += offsetY;

    transformHandler.MoveObject(direction);




    GLfloat updatedVertices[12];

    const GLfloat* verticesFromHandler = transformHandler.GetVertices();

    for (int i = 0; i < 12; ++i)
    {
        updatedVertices[i] = verticesFromHandler[i];
    }

    // Bind the buffer and update the vertex data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(updatedVertices), updatedVertices); // Use glBufferSubData for partial updates
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    debugOutput.outputGreenText("**SUCCESS**::DRAWER::AttributePointersSet::[Engine/Renderer/Drawer.h]");
}

void Drawer::DeleteDrawer()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    debugOutput.outputGreenText("**SUCCESS**::DRAWER::DrawerDeleted::[Engine/Renderer/Drawer.h]");
}