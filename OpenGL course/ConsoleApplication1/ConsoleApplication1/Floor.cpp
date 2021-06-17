#include "Floor.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
Floor::Floor()
{
}

void Floor::CreateTriangle1()
{
	float vertices[] = {
		// positions         // texture coords
		 0.2f,  0.2f, 0.0f,   0.0f, 0.0f,   // top right
		 0.7f, -0.5f, 0.0f,   0.0f, 1.0f,   // bottom right
		-0.7f, -0.5f, 0.0f,   1.0f, 1.0f,   // bottom left

		-0.7f, -0.5f,0.0f,  1.0f, 1.0f,   // top right
		-0.2f, 0.2f,0.0f,  1.0f, 0.0f,   // bottom right
		0.2f, 0.2f,0.0f,   0.0f, 0.0f,   // bottom left
	};
	//alocar memoria de UM VAO e dar o bind nele
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);

}


GLuint Floor::getVAO()
{
	return VAO;
}


GLuint Floor::getVBO()
{
	return VBO;
}

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
