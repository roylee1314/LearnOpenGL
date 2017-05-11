#pragma once
#include <iostream>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Transformations.h"
#include "CoordSystem.h"
#include "BookCamera.hpp"

GLuint screenWidth = 800, screenHeight = 600;


class MainWindow
{
public:
	MainWindow();
	void work();
	~MainWindow();


};

