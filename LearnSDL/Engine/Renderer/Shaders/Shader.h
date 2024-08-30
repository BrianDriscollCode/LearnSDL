#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../../Debug/DebugOutput.h"
#include "../../libraries/glm/glm.hpp"
#include "../../libraries/glm/gtc/matrix_transform.hpp"
#include "../../libraries/glm/gtc/type_ptr.hpp"

class Shader
{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath)
    {
        DebugOutput debugOutput(true);

        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try
        {
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);

            std::cout << " Files Opened " << std::endl;

            std::stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            std::cout << " Files Read " << std::endl;

            vShaderFile.close();
            fShaderFile.close();

            std::cout << " Files closed " << std::endl;

            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();

            std::cout << " File code streamed " << std::endl;

            debugOutput.outputGreenText("**SUCCESS**::SHADER::FILE_READ_SUCCESSFULLY::[Redenderer/Shaders/Shader.h]");
            std::cout << "VERTEX SHADER PATH: " << vertexPath << std::endl;
            std::cout << "FRAGMENT SHADER PATH: " << fragmentPath << std::endl;
        }
        catch (std::ifstream::failure& e)
        {
            debugOutput.outputRedText("ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ::[Redenderer/Shaders/Shader.h]");
            debugOutput.outputRedText(e.what());
            std::cout << "VERTEX SHADER PATH: " << vertexPath << std::endl;
            std::cout << "FRAGMENT SHADER PATH: " << fragmentPath << std::endl;
            std::cout << "FRAGMENT SHADER PATH: " << fragmentPath << std::endl;
        }
        std::cout << " test0 " << std::endl;
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        std::cout << " test " << std::endl;
        unsigned int vertex, fragment;
        std::cout << " test2 " << std::endl;
        // compile vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER); // excpetion null here
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        std::cout << " test3 " << std::endl;
        int success;
        char infoLog[512];
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        std::cout << " test4 " << std::endl;
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            debugOutput.outputRedText("ERROR::SHADER::VERTEX::COMPILATION_FAILED::[tools/shader.h]");
            debugOutput.outputRedText(infoLog);
        }
        else
        {
            debugOutput.outputGreenText("**SUCCESS**::SHADER::VERTEX::COMPILED::[tools/shader.h]");
        }

        // compile fragment shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            debugOutput.outputRedText("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED::[tools/shader.h]");
            debugOutput.outputRedText(infoLog);
        }
        else
        {
            debugOutput.outputGreenText("**SUCCESS**::SHADER::FRAGMENT::COMPILED::[tools/shader.h]");
        }

        // Create program object
        ID = glCreateProgram();

        // Link shaders to program
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);

        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            debugOutput.outputRedText("ERROR::SHADER::PROGRAM_LINK::LINKING_FAILED::[tools/shader.h]");
            debugOutput.outputRedText(infoLog);
        }
        else
        {
           debugOutput.outputGreenText("**SUCCESS**::SHADER::PROGRAM::LINKED::[tools/shader.h]");
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void use()
    {
        glUseProgram(ID);
    }

    unsigned int getProgram() const
    {
        return ID;
    }

    // utility functions
    void setBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    void setInt(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setFloat(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setVec3(const std::string& name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }

    void setVec3(const std::string& name, const glm::vec3& value) const
    {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    void setVec4(const std::string& name, const glm::vec4& value) const
    {
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    void setMat4(const std::string& name, const glm::mat4& mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
};

#endif