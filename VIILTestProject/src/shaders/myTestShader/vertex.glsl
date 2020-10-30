#version 330 core

layout(location = 0) in vec3 myPosition;	
layout(location = 1) in vec2 inTextureCoords;

uniform float aspectRatio;
uniform mat4 vpMatrix;
uniform mat4 objTransformMatrix;

out vec2 textureCoords;

void main()
{
	textureCoords = inTextureCoords;
	gl_Position = ((vpMatrix * objTransformMatrix) * (vec4(aspectRatio, 1, 1, 1) * vec4(myPosition, 1)));
}