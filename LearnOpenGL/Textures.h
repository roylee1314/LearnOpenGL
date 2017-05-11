#pragma once
#include <iostream>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include "Shader.h"

class Textures
{
public:
	Textures();
	void prepare();
	void draw();
	void finish();
	unsigned char* readImage(char* name, int* width, int* height);
	~Textures();
	Shader shader;
	GLuint VBO, VAO, EBO, texture0, texture1;

};

