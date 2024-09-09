
#include "Drawer.h"

#include "../Engine/Debug/DebugOutput.h"

// Drawer constructor
Drawer::Drawer(bool activate, SDL_Window* gWindowRef)
    : debugOutput(true), squareVAO(0), VBO(0), EBO(0), offsetX(0.1f), offsetY(0.1f), gWindow(gWindowRef)
{
}

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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind the VBO
    glBindVertexArray(0);

    debugOutput.outputGreenText("**SUCCESS**::DRAWER::SQUARE_BUFFERS_LOADED::[Engine/Renderer/Drawer.h]");
}

// Draw

void Drawer::DrawSquare(Entity entity, Color color, glm::vec2 scale) 
{

    // defines the 4x4 matrix for doing calculations via glm library
    glm::mat4 model = glm::mat4(1.0f);

    // Movement and scaling
    model = glm::translate(model, entity.actualPosition);
    model = glm::scale(model, glm::vec3(scale, 1.0f));

    // Choose Color

    glm::vec4 colorPicker = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);

    switch (color)
    {
        case Color::BLUE:
            colorPicker = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
            break;
        case Color::GREEN:
            colorPicker = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
            break;
        case Color::YELLOW:
            colorPicker = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case Color::ORANGE:
            colorPicker = glm::vec4(1.0f, 0.5f, 0.0f, 1.0f);
            break;
        case Color::RED:
            colorPicker = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
            break;
        default:
            colorPicker = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
            break;
    }

    // Fragment Shader Color Edit
    GLint colorLocation = glGetUniformLocation(squareShader->ID, "userColor");
    glUseProgram(squareShader->ID);
    glUniform4f(colorLocation, colorPicker.x, colorPicker.y, colorPicker.z, colorPicker.w);

    // Vertex shader (transformation, scale, rotation)
    GLint modelLoc = glGetUniformLocation(squareShader->getProgram(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // Draw the object
    squareShader->use();
    glBindVertexArray(squareVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


}

void Drawer::EndDraw()
{
    SDL_GL_SwapWindow(gWindow);
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