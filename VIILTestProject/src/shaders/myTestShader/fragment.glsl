#version 330 core

layout(location = 0) out vec4 colour;	

in vec2 textureCoords;
uniform sampler2D image;

void main()
{		
	colour = texture(image, textureCoords);
}