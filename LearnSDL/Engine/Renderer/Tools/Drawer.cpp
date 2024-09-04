
#include "Drawer.h"

#include "../Engine/Debug/DebugOutput.h"

// Drawer constructor
Drawer::Drawer(bool activate)
    : debugOutput(true), squareVAO(0), VBO(0), EBO(0), offsetX(0.1f), offsetY(0.1f), transformHandler() {}

// Initialize Drawer
void Drawer::initializeSquareVAO() {
    squareShader = std::make_unique<Shader>("./Engine/Renderer/Shaders/Resources/BasicSquare.vert", "./Engine/Renderer/Shaders/Resources/BasicSquare.frag");

    // Initialize member variables
    GLfloat vertices[] = {
        -0.1f,  0.1f, 0.0f,  // Top-left
        -0.1f, -0.1f, 0.0f,  // Bottom-left
         0.1f, -0.1f, 0.0f,  // Bottom-right
         0.1f,  0.1f, 0.0f   // Top-right
    };

    GLuint indices[] = {
        0, 1, 2,  // First triangle
        2, 3, 0   // Second triangle
    };

    debugOutput.outputGreenText("Start Drawer");
    glGenVertexArrays(1, &squareVAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(squareVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //transformHandler.SetInitialVertices(vertices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind the VBO
    glBindVertexArray(0);

    debugOutput.outputGreenText("**SUCCESS**::DRAWER::BUFFERS_LOADED::[Engine/Renderer/Drawer.h]");
}

// Draw

void Drawer::DrawSquare(SDL_Window* gWindow, Entity player) {

    //glm::vec3 boxPosition = glm::vec3(0.5f, 0.5f, 0.0f);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, player.position);

    GLint modelLoc = glGetUniformLocation(squareShader->getProgram(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    squareShader->use();
    glBindVertexArray(squareVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    SDL_GL_SwapWindow(gWindow);
}

// Move square (if applicable)

//void Drawer::MoveSquare()
//{
//
//}
 

void Drawer::MoveSquare(KeyPress directionX, KeyPress directionY) {
    transformHandler.MoveObject(directionX, directionY);

    GLfloat updatedVertices[12];
    const GLfloat* verticesFromHandler = transformHandler.GetVertices();

    for (int i = 0; i < 12; ++i) {
        updatedVertices[i] = verticesFromHandler[i];
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(updatedVertices), updatedVertices); // Use glBufferSubData for partial updates
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Delete Drawer
void Drawer::DeleteDrawer() {
    glDeleteVertexArrays(1, &squareVAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    if (squareShader) {
        glDeleteProgram(squareShader->getProgram());
    }

    debugOutput.outputGreenText("**SUCCESS**::DRAWER::DrawerDeleted::[Engine/Renderer/Drawer.h]");
}