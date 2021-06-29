#pragma once


//#include<GL/glew.h>
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include<stdio.h>
#include "VAO.h"
#include "VBO.h"


static const char* vShader2 = "                                \n\
#version 330 core \n\
layout(location = 0) in vec3 pos; \n\
layout(location = 1) in vec3 aColor; \n\
layout(location = 2) in vec2 aTexCoord; \n\
 \n\
out vec3 ourColor;\n\
out vec2 TexCoord;\n\
uniform mat4 model;\n\
uniform mat4 view;\n\
uniform mat4 projection;\n\
\n\
void main()\n\
{\n\
	gl_Position = vec4(1.0 * pos.x, 1.0 * pos.y,  pos.z, 1.0); \n\
	ourColor = aColor;\n\
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n\
}\n\
";
static const char* fShader2 = "                            \n\
#version 330 core \n\
out vec4 FragColor; \n\
 \n\
in vec3 ourColor; \n\
in vec2 TexCoord;\n\
\n\
// texture sampler \n\
uniform sampler2D texture2; \n\
\n\
void main() \n\
{ \n\
	vec4 texColor = texture(texture2, TexCoord); \n\
   if(texColor.a < 0.1)\n\
	discard;\n\
	FragColor = texColor;\n\
} \n\
";


class Tree
{
public:

	Tree();
	void CreateTriangle1(VAO& vao);

	GLuint getVAO();

	GLuint getVBO();
	void GenTexture();
	unsigned int getTexture();
	void printVertex();
	float *getVertex();

private:
//	GLuint VAO, VBO;
	unsigned int texture;
	float* vertex;

};

