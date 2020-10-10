#include "Game.h"
#include"Texture.h"

using namespace std;

//
//update input
//void updateInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, GLFW_TRUE);
//	}
//}
//resize window
//
//void keybordMove(GLFWwindow* window, Mesh &mesh)
//{
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//	{
//		mesh.move(glm::vec3(0.0f, 0.0f, 0.01f));
//	}
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//	{
//		mesh.move(glm::vec3(0.0f, 0.0f, -0.01f));
//	}
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//	{
//		mesh.move(glm::vec3(-0.01f, 0.0f, 0.0f));
//			}
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//	{
//		mesh.move(glm::vec3(0.01f, 0.0f, 0.0f));
//	}
//	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
//	{
//		mesh.rotate(glm::vec3(0.0f, -1.0f, 0.0f));
//	}
//	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
//	{
//		mesh.rotate(glm::vec3(0.0f, 1.0f, 0.0f));
//	}
//	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
//	{
//		mesh.scaleUp(glm::vec3(-0.5f));
//	}
//	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
//	{
//		mesh.scaleUp(glm::vec3(+0.5f));
//	}
//}
//
//GLFWwindow* createWindow(const char* title, const int width, const int height, int& fbWidth, int& fbHeight, int GLmajorVersion, int GLminorVersion, bool resizable)
//{
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLmajorVersion);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLminorVersion);
//	glfwWindowHint(GLFW_RESIZABLE, resizable);
//
//	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
//
//	glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
//	glfwSetFramebufferSizeCallback(window, Game::framebuffer_resize_callback);
//	//glViewport(0, 0, framebufferWIdth, framebufferHeight);
//
//	glfwMakeContextCurrent(window);
//
//	return window;
//}
//
int main()
{
	glfwInit();

	Game game("Opengl - zaliczenie ;)", 800, 800, 4, 4, false);

	glewExperimental = GL_TRUE;
	//glewInit();

	//error
	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::main.CPP::GLEW INIT FAILED" << "\n";
		glfwTerminate();
	}

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

	}

	//main loop
	while (!game.getWindowShouldClose())
	{
		//update input
		game.update();
		game.render();
	}
	//glewExperimental = GL_TRUE; 

	return 0;
}