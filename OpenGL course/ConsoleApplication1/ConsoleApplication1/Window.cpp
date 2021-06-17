#include "Window.h"





Window::Window()
{
	WIDTH = 800;
	HEIGHT = 800;
}

Window::Window(GLint _height, GLint _width)
{
	HEIGHT = _height;
	WIDTH = _width;
}

int Window::Init()
{
	if (!glfwInit())
	{
		cout << "GLFW initialisation failed!";
		glfwTerminate();
		return 1;
	}
	//setup glfw window properties
   //OpenGLversion
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//core profile = no backwards compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


	mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Teste window", NULL, NULL);
	if (!mainWindow)
	{
		cout << "GLFW Window creation failed";
		glfwTerminate();
		return 1;
	}



	//Get bufffer size information(parte da tela q vai lidar com os dados de opengl a serem mostrados)
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//set context for glew to use
	glfwMakeContextCurrent(mainWindow);

	//Allow modern extension features
	glewExperimental = GL_TRUE;


	if (glewInit() != GLEW_OK)
	{
		cout << "glew init failed";
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;

	}


	//Setup viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(mainWindow);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(mainWindow);
}


