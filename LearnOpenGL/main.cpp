//#include <iostream>
//// GLEW
//#define GLEW_STATIC
//#include <GL/glew.h>
//// GLFW
//#include <GLFW/glfw3.h>
//#include <glm/gtc/quaternion.hpp>
//#include <glm/gtx/quaternion.hpp>
//#include "Transformations.h"
//#include "CoordSystem.h"
//#include "BookCamera.hpp"
//
//GLuint screenWidth = 800, screenHeight = 600;
//
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void Do_Movement();
//const double PI = atan(1.)*4.;
//// Camera
//
//bool keys[1024];
//GLfloat lastX = 400, lastY = 300;
//bool firstMouse = true;
//
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//Camera* camera = new Camera();
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//	// Options
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//
//	// Define the viewport dimensions
//	glViewport(0, 0, screenWidth, screenHeight);
//
//	auto hello = CoordSystem();
//	
//	hello.camera = camera;
//
//	// Game loop
//	while (!glfwWindowShouldClose(window))
//	{
//
//		// Set frame time
//		GLfloat currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//
//		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
//		glfwPollEvents();
//		Do_Movement();
//		// Render
//		// Clear the colorbuffer
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		
//		hello.drawLyingFace(screenWidth, screenHeight);
//		// Swap the screen buffers
//		glfwSwapBuffers(window);
//	}
//	
//	glfwTerminate();
//	delete camera;
//	return 0;
//}
//
//// Moves/alters the camera positions based on user input
//void Do_Movement()
//{
//	// Camera controls
//	if (keys[GLFW_KEY_W])
//		camera->processKeyboard(FORWARD, deltaTime);
//	if (keys[GLFW_KEY_S])
//		camera->processKeyboard(BACKWARD, deltaTime);
//	if (keys[GLFW_KEY_A])
//		camera->processKeyboard(LEFT, deltaTime);
//	if (keys[GLFW_KEY_D])
//		camera->processKeyboard(RIGHT, deltaTime);
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	//cout << key << endl;
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	if (key >= 0 && key < 1024)
//	{
//		if (action == GLFW_PRESS)
//			keys[key] = true;
//		else if (action == GLFW_RELEASE)
//			keys[key] = false;
//	}
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	GLfloat xoffset = xpos - lastX;
//	GLfloat yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left
//
//	lastX = xpos;
//	lastY = ypos;
//
//	camera->processMouseMovement(xoffset, yoffset);
//}
//
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//
//	camera->processMouseScroll(yoffset);
//}
//
////int main()
////{
////	glm::quat q = glm::angleAxis((float) (PI / 2.0), glm::vec3(0.0f, 1.0f, 0.0f));
////	glm::vec3 v = q * glm::vec3(1.0f, 0.0f, 0.0f) ;
////	std::cout << v.x << " " << v.y << " " << v.z << std::endl;
////
////	std::cout << glm::dot(v ,glm::vec3(0.0f, 0.0f, 1.0f)) << std::endl;
////	std::cout << cosf(3.14) << std::endl;
////	return 0;
////}