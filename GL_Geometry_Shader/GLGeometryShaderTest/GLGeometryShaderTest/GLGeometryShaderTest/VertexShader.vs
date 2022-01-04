#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 pos;

layout(location = 1) in vec3 dir;

layout(location = 2) in vec3 color;

out vec4 vertexColor;
out vec3 direction;

uniform float time;
uniform mat4 modelView;
uniform mat4 modelProj;

void main() {
	gl_Position = modelProj * modelView * vec4(pos, 1.0f);
	vertexColor = vec4(color, 1.0f);
	//vertexColor = vec4(1,1,0, 1.0f);
	direction = dir;
}