#pragma once
#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include "HelloTriangle.h"
#include "Shader.h"
class HelloTriangle
{
public:
	HelloTriangle();
	~HelloTriangle();
	Shader shader;
	
	int drawTriangleWithTime();

};

