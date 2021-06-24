#include "Tree.h"

#include "stb_image.h"
Tree::Tree()
{
}

void Tree::CreateTriangle1()
{
	float vertices[] = {
		// positions         // texture coords
		 0.2,  0.5f, 0.0f,    0.0f, 0.0f,   // top right
		 0.2f, -0.5f, 0.0f,   0.0f, 1.0f,   // bottom right
		-0.2f, -0.5f, 0.0f,   1.0f, 1.0f,   // bottom left

		-0.2f, -0.5f,0.0f, 1.0f, 1.0f,   // top right
		-0.2f, 0.5f,0.0f,  1.0f, 0.0f,   // bottom right
		 0.2f, 0.5f,0.0f,   0.0f, 0.0f,   // bottom left
	};
	vertex = new float[30]{
		// positions         // texture coords
		 0.2,  0.5f, 0.0f,    0.0f, 0.0f,   // top right
		 0.2f, -0.5f, 0.0f,   0.0f, 1.0f,   // bottom right
		-0.2f, -0.5f, 0.0f,   1.0f, 1.0f,   // bottom left

		-0.2f, -0.5f,0.0f, 1.0f, 1.0f,   // top right
		-0.2f, 0.5f,0.0f,  1.0f, 0.0f,   // bottom right
		 0.2f, 0.5f,0.0f,   0.0f, 0.0f,   // bottom left
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



GLuint Tree::getVAO()
{
	return VAO;
}


GLuint Tree::getVBO()
{
	return VBO;
}

void Tree::GenTexture()
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
		unsigned char* data = stbi_load("tree.png", &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
}

unsigned int Tree::getTexture()
{
	return texture;
}

void Tree::printVertex()
{
	
	for (int i = 0; i < 30; i++) {
		std::cout << vertex[i] << std::endl;
	}
}

float* Tree::getVertex()
{
	return vertex;
}

