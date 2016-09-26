#pragma once

#include "gl-inl.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class OBJObject
{
private:
std::vector<unsigned int> indices;
std::vector<glm::vec3> vertices;
std::vector<glm::vec3> normals;
glm::mat4 toWorld;

public:
	OBJObject(const char* filepath);

	void parse(const char* filepath);
	void draw();
};
