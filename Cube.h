#pragma once

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <OpenGL/gl.h>
#endif /* __APPLE__ */
#include <OpenGL/glext.h>


#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Cube
{
public:
	Cube(float);
	~Cube();

	glm::mat4 toWorld;

	float size;
	float angle;

	void draw();
	void update();

	void spin(float);
};
