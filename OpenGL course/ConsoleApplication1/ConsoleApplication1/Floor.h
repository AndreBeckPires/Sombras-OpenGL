#pragma once


#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include<stdio.h>


static const char* vShader = "                                \n\
#version 330 core \n\
layout(location = 0) in vec3 pos; \n\
layout(location = 1) in vec3 aColor; \n\
layout(location = 2) in vec2 aTexCoord; \n\
 \n\
out vec3 ourColor;\n\
out vec2 TexCoord;\n\
\n\
void main()\n\
{\n\
	gl_Position = vec4(1.0 * pos.x, 1.0 * pos.y,  pos.z, 1.0); \n\
	ourColor = aColor;\n\
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n\
}\n\
";
static const char* fShader = "                            \n\
#version 330 core \n\
out vec4 FragColor; \n\
 \n\
in vec3 ourColor; \n\
in vec2 TexCoord;\n\
\n\
// texture sampler \n\
uniform sampler2D texture1; \n\
\n\
void main() \n\
{ \n\
	FragColor = texture(texture1, TexCoord); \n\
} \n\
";


class Floor
{
public:
	
	Floor();
	void CreateTriangle1();
	GLuint getVAO();
	GLuint getVBO();
	void GenTexture();
	unsigned int getTexture();

private:
	unsigned int texture;
	GLuint VAO, VBO;

};

