#pragma once
#include "shader.h"
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transformations
{
public:
	Transformations();
	~Transformations();
	void draw();
	Shader* shader;
	GLuint VBO, VAO, EBO, texture1, texture2;
	int pace;
	glm::mat4 transform;

};

