#ifndef INITIALIZERENDERER_H
#define INITIALIZERENDERER_H

#include <GL/glew.h>
#include <SDL_opengl.h>

#include "../Debug/DebugOutput.h"

class InitializeRenderer {
public:
    GLuint shaderProgram;
    GLuint& VAO;
    GLuint& VBO;
    DebugOutput debugOutput;

    // Member variables for vertices and indices
    GLfloat vertices[12];
    GLuint indices[6];

    // Constructor that initializes VAO, VBO, and shaderProgram
    InitializeRenderer(GLuint& VAOr, GLuint& VBOr, GLuint& shaderProg)
        : VAO(VAOr), VBO(VBOr), shaderProgram(shaderProg), debugOutput(true)
    {
        // Initialize member variables
        GLfloat tempVertices[] = {
            -0.1f,  0.1f, 0.0f,  // Top-left
            -0.1f, -0.1f, 0.0f,  // Bottom-left
             0.1f, -0.1f, 0.0f,  // Bottom-right
             0.1f,  0.1f, 0.0f   // Top-right
        };

        GLuint tempIndices[] = {
            0, 1, 2,  // First triangle
            2, 3, 0   // Second triangle
        };

        // Copy temp arrays to member variables
        std::copy(std::begin(tempVertices), std::end(tempVertices), std::begin(vertices));
        std::copy(std::begin(tempIndices), std::end(tempIndices), std::begin(indices));

        // Set the attributes for OpenGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    }

    void StartRenderer()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        GLuint EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        debugOutput.outputGreenText("**SUCCESS**::INITIALIZERENDERER::BUFFERSLOADED::[Engine/Renderer/InitializeRenderer.h]");

        // Initialize OpenGL clear color
        glClearColor(0.f, 0.f, 0.f, 1.f);
    }

    void terminateRenderer()
    {
        debugOutput.outputGreenText("**SUCCESS**::TERMINATERENDERER::CLOSING::[Engine/Renderer/InitializeRenderer.h]");
        // Deallocate OpenGL resources
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteProgram(shaderProgram);
    }
};

#endif