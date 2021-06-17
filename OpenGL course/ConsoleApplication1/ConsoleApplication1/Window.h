#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include<stdio.h>
using namespace std;

class Window
{
public:
	Window();
	Window(GLint _height, GLint _width);
	int Init();
	bool shouldClose();
	void swapBuffers();

	
	
private:
	GLint WIDTH, HEIGHT;
	GLFWwindow* mainWindow;
	
	
};

