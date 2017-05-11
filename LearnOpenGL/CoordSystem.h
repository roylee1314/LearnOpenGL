#pragma once
#include "Shader.h"
#include "Camera.h"
class CoordSystem
{
public:
	CoordSystem();
	~CoordSystem();
	void drawLyingFace(GLfloat width, GLfloat height);
	void prepareDrawingCubeFace();
	void drawCubeFace(GLfloat width, GLfloat height); 
	
	Shader shader;
	GLuint VAO, VBO, EBO, texture0, texture1;
	float delta;
	float lastTime;
	Camera* camera;
};

