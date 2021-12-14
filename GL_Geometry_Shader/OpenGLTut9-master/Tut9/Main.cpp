#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>

#include "ShaderLoader.h"

void createPointsBuffer();
void renderScene();

GLuint programID;
GLuint pointsBuffer;

int main(int argc, char **argv) {
	//initialise GLFW
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialise GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, 0);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(700, 500, "OpenGLTut9 - Geometry Shading", NULL, NULL);
	if (window == NULL){
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowPos(window, 400, 200);

	//initialize GLEW
	glewExperimental = true;		// Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//need to be after glewInit(), otherwise got error
	programID = LoadShaders("VertexShader.vertexshader", "FragmentShader.fragmentshader", "GeometryShader.geometryshader");

	createPointsBuffer();

	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

		renderScene();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

void createPointsBuffer() {
	GLfloat points[] = {
		//Coord				   //Colour			  //Sides
		-0.45f, 0.45f, 1.0f,   0.0f, 0.0f, 1.0f,   4.0f,
		0.45f, 0.45f, 0.0f,    1.0f, 0.0f, 1.0f,   8.0f,
		0.45f, -0.45f, 0.0f,   0.0f, 1.0f, 1.0f,   16.0f,
		-0.45f, -0.45f, 1.0f,  1.0f, 0.0f, 1.0f,   32.0f
	};

	glGenBuffers(1, &pointsBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, pointsBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
}

void renderScene() {
	// Render frame
	glClear(GL_COLOR_BUFFER_BIT);

	//use the shader
	glUseProgram(programID);

	// Specify layout of point data
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, pointsBuffer);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, pointsBuffer);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
		7 * sizeof(float), (void*)(2 * sizeof(float)));

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, pointsBuffer);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE,
		7 * sizeof(float), (void*)(6 * sizeof(float)));

	glDrawArrays(GL_POINTS, 0, 4);

	glDisableVertexAttribArray(0);
}