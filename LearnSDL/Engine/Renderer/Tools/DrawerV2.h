#ifndef DRAWERV2_H
#define DRAWERV2_H

#include <GL/glew.h>
#include <SDL_opengl.h>
#include <SDL.h>

#include "../Engine/Debug/DebugOutput.h"
#include "../Tools/Handlers/TransformHandler.h"

// Utilities

#include "../Engine/Utilities/Enum/KeyPress.h"

struct DrawerV2
{
public:
	GLuint VAO[3];
	GLuint VBO[3];
	GLuint EBO[3];
	float offsetX;
	float offsetY;
	DebugOutput debugOutput;
	TransformHandler transformHandler;

	void initalizeDrawer();
	void Draw(SDL_Window* gWindow);
	void MoveSquare(KeyPress directionX, KeyPress directionY);
	void DeleteDrawer();
};


#endif