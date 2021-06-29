#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec3 ourColor;

// Inputs the texture coordinates from the Vertex Shader
in vec2 TexCoord;
// Gets the Texture Unit from the main function
uniform sampler2D tex0;

void main()
{
	FragColor = texture(tex0, TexCoord);
}