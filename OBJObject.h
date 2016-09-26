#pragma once

#include "gl-inl.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <string>

class OBJObject
{
	std::vector<unsigned int> indices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	glm::mat4 toWorld;

public:
	OBJObject(std::string const& filepath);

	void parse(std::string const& filepath);
	void draw();
};
