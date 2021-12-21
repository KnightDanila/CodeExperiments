#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec2 pos;

layout(location = 1) in vec4 color;

layout(location = 2) in float sides;

out vec4 vertexColor;
out float vSides;

uniform float time;

void main() {
    gl_Position.xy = pos;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
	
	vertexColor = color;
	
	vSides = sides;
}