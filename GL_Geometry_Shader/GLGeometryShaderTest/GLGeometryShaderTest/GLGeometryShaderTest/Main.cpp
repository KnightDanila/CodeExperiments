#include <stdio.h>
#include <stdlib.h>

#include <glew.h>
#include <glfw3.h>
#include <freeglut.h>
#include <glm\glm.hpp>
#include "glm\gtc\random.hpp"
#include <vector>

#include "ShaderLoader.h"
#include "GLCamera.h"

void createPointsBuffer();
void renderScene();

GLShader *shader;
//GLuint pointsBuffer;
GLuint startPointsBuffer;
GLuint endPointsBuffer;
GLuint colorPointsBuffer;


int SCR_WIDTH = 800;
int SCR_HEIGHT = 600;

struct Vertex {
	float _x, _y, _z;
	Vertex(float x, float y, float z) {
		_x = x;
		_y = y;
		_z = z;
	}
};

void makeVectorOfLine(std::vector<Vertex>& v, int size) {
	// f(x) = [0 1]
	for (float i = 0; i <= 1; i += 1.0f / size) 
	{
		v.push_back(Vertex(i, 0, 0));
	}
}

void makeVectorOfColor(std::vector<Vertex>& vc, int size) {
	for (int i = 0; i < size; i++)
	{
		//vc.push_back(glm::vec3(0.5, glm::linearRand(0, 1), glm::linearRand(0, 1)));
		vc.push_back(Vertex(1, 1, 0));
	}
}

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

	GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGLTut9 - Geometry Shading", NULL, NULL);
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
	shader = new GLShader("VertexShader.vs", "FragmentShader.fs", "GeometryShader.gs");

	createPointsBuffer();
	Camera* Cam = new GLCameraTarget();

	Cam->setPerspective(glm::radians(45.0f), (float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 10.0f);

	float angle = 0;
	float PI = 3.14159265;
	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		
		Cam->setPos(glm::vec3(0, 0, 2));
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
			Cam->setPos(glm::vec3(0, 0, 2));
		if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
			angle = glfwGetTime() * 50.0f;
			Cam->setPos(glm::vec3(2 * cos(angle * PI / 180), 2, 2 * sin(angle * PI / 180)));
		}
		if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
			angle = glfwGetTime() * 50.0f;
			Cam->setPos(glm::vec3(2,2 * sin(angle * PI / 180), 2 * cos(angle * PI / 180)));
		}
		//use the shader
		shader->use();
		shader->setFloat("time", glfwGetTime());
		shader->setMat4("modelView", Cam->getMat4ModelView());
		shader->setMat4("modelProj", Cam->getMat4ModelProj());
		shader->setFloat("time", glfwGetTime());
		renderScene();
		glUseProgram(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

void createPointsBuffer() {
	std::vector<Vertex> v;
	std::vector<Vertex> vc;
	makeVectorOfLine(v, 3);
	makeVectorOfColor(vc, v.size()-1);

	glGenBuffers(1, &startPointsBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, startPointsBuffer);
	glBufferData(GL_ARRAY_BUFFER, (v.size() - 1) * sizeof(Vertex), &v[0], GL_STATIC_DRAW);

	glGenBuffers(1, &endPointsBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, endPointsBuffer);
	glBufferData(GL_ARRAY_BUFFER, (v.size() - 1) * sizeof(Vertex), &v[1], GL_STATIC_DRAW);

	glGenBuffers(1, &colorPointsBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorPointsBuffer);
	glBufferData(GL_ARRAY_BUFFER, vc.size() * sizeof(Vertex), &vc[0], GL_STATIC_DRAW);
}

//void 

void renderScene() {
	// Render frame
	glClear(GL_COLOR_BUFFER_BIT);

	// Specify layout of point data
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, startPointsBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, endPointsBuffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, colorPointsBuffer);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glDrawArrays(GL_POINTS, 0, 3);

	glDisableVertexAttribArray(0);
}