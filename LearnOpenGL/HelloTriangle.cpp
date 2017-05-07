
#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include "HelloTriangle.h"
#include "Shader.h"

HelloTriangle::HelloTriangle()
{
	this->shader = Shader("vs/triangle.vert", "ps/triangle.frag"); 
}

int HelloTriangle::drawTriangleWithTime()
{
	shader.Use();
	GLfloat vertices[] = {
		// Positions         // Colors
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // Bottom Left
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f   // Top 
	};
	GLuint VBO, VAO, EBO;

	return 0;
}


HelloTriangle::~HelloTriangle()
{
}
