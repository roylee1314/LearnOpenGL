#include "Camera.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


Camera::~Camera()
{
}



Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up) :zoom(ZOOM), movementSpeed(SPEED), mouseSensitivity(SENSITIVTY)
{
	this->position = position;
	this->front = front;
	this->up = up;
	this->right = glm::normalize(glm::cross(this->front, this->up));
	

}


void Camera::processKeyboard(Camera_Movement direction, GLfloat deltaTime)
{
	GLfloat velocity = this->movementSpeed * deltaTime;
	if (direction == Camera_Movement::FORWARD)
	{
		this->position += this->front * velocity;
	}
	else if (direction == Camera_Movement::BACKWARD)
	{
		this->position -= this->front * velocity;
	}
	else if (direction == Camera_Movement::RIGHT)
	{
		this->position += this->right * velocity;
	}
	else if (direction == Camera_Movement::LEFT)
	{
		this->position -= this->right * velocity;
	}
	else if (direction == Camera_Movement::UP)
	{
		this->position += this->up * velocity;
	}
	else if (direction == Camera_Movement::DOWN)
	{
		this->position -= this->up * velocity;
	}
	//std::cout << "position" << this->position.x << this->position.y << this->position.z<< std::endl;
}
void Camera::processMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
	xoffset *= this->mouseSensitivity;
	yoffset *= this->mouseSensitivity;
	glm::quat xquat = glm::angleAxis(-glm::radians(xoffset), this->up);
	
	//std::cout << "mouse" << xoffset << " " << yoffset << std::endl;
	glm::quat yquat = glm::angleAxis(glm::radians(yoffset), this->right);
	this->front = yquat *xquat * this->front;
	//this->up = yquat * this->up;
	this->right = glm::normalize(glm::cross(this->front, glm::vec3(0.0f, 1.0f, 0.0f)));
	this->up = glm::normalize(glm::cross(this->right, this->front));


}
void Camera::processMouseScroll(GLfloat yoffset)
{
	yoffset *= mouseSensitivity;
	if (this->zoom >= 1.0f && this->zoom <= 45.0f)
		this->zoom -= yoffset;
	if (this->zoom <= 1.0f)
		this->zoom = 1.0f;
	if (this->zoom >= 45.0f)
		this->zoom = 45.0f;
	std::cout << "zoom" << this->zoom << std::endl;
	
}
void updateCameraVectors()
{
	
}

