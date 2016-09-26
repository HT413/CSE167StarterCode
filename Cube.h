#pragma once

#include "gl-inl.h"

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
