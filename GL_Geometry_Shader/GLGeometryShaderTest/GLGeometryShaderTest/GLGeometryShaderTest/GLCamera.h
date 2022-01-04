#ifndef GLCAMERA_H
#define GLCAMERA_H

  /*
   Free camera - CS:GO, Doom
   Target camera - Chess,
   */

#include <glm/glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

class Camera {
public:

	virtual void setPerspective(float fov, float aspect, float near, float far) = 0;
	virtual void setPos(glm::vec3 pos) = 0;

	virtual glm::vec3 getPos() = 0;

	virtual glm::mat4 getMat4ModelView() = 0;
	virtual glm::mat4 getMat4ModelProj() = 0;


protected:
	glm::vec3 _pos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 _direction = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 _modelview = glm::mat4(0.0f);
	glm::mat4 _modelproj = glm::mat4(0.0f);
};

class GLCameraTarget : public Camera {
public:

	void setPerspective(float fov, float aspect, float near1, float far1) {
		/*
		// Calculate The Aspect Ratio Of The Window
		// The parameters are:
		// (view angle, aspect ration of the width to the height,
		//  The closest distance to the camera before it clips,
		// FOV, Ratio,  The farthest distance before it stops drawing)
		 */
		 //gluPerspective(45.0f, (GLfloat) width / (GLfloat) height, 0.5f, 3000.0f);

		glMatrixMode(GL_PROJECTION);
		_modelproj = glm::perspective(fov, aspect, near1, far1);
		glLoadMatrixf(glm::value_ptr(_modelproj));
	};

	void setPos(glm::vec3 pos) {
		glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 direction = glm::normalize(pos - target);
		_modelview = glm::lookAt(pos, direction, glm::vec3(0, 1, 0));
		//glMatrixMode(GL_PROJECTION);
		//GL_PROJECTION_MATRIX
		//glLoadMatrixf(&modelview);
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(_modelview));
	};

	glm::vec3 getPos() {
		return _pos;
	};

	glm::mat4 getMat4ModelView() {
		return _modelview;
	};

	glm::mat4 getMat4ModelProj() {
		return _modelproj;
	};
};


#endif /* GLCAMERA_H */

