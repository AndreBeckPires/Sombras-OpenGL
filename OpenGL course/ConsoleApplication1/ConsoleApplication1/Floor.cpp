#include "Floor.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
Floor::Floor()
{
}

void Floor::CreateTriangle1(VAO& vao)
{
	GLfloat vertices[] = {
		// positions               COLORS      /  // texture coords
		 0.7f, -0.5f, 0.7f,  0.83f, 0.70f, 0.44f,  0.0f, 0.0f,   // top right
		 0.7f, -0.5f, -0.7f,  0.83f, 0.70f, 0.44f,  0.0f, 1.0f,   // bottom right
		-0.7f, -0.5f, -0.7f,  0.83f, 0.70f, 0.44f,  1.0f, 1.0f,   // bottom left
				  
		0.7f,  -0.5f, 0.7f,   0.83f, 0.70f, 0.44f,  1.0f, 1.0f,   // top right
		-0.7f, -0.5f, 0.7f,   0.92f, 0.86f, 0.76f,  1.0f, 0.0f,   // top left
		-0.7f, -0.5f,-0.7f,   0.92f, 0.86f, 0.76f,  0.0f, 0.0f,   // bottom left
	};

	VBO vbo(vertices, sizeof(vertices));

	// Links VBO attributes such as coordinates and colors to VAO
	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));


	vao.Unbind();
	vbo.Unbind();

}


//GLuint Floor::getVAO()
//{
//	return vao;
//}
//
//
//GLuint Floor::getVBO()
//{
//	return VBO;
//}

void Floor::GenTexture()
{
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load("grass.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

unsigned int Floor::getTexture()
{
	return texture;
}

void Floor::bindVao()
{

}
