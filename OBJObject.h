#ifndef OBJOBJECT_H
#define OBJOBJECT_H

#include <Windows.h>
#include <iostream>
#include <sstream>


#ifdef __APPLE__
#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h> // Remove this line in future projects
#else
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>


using namespace std;

class OBJObject
{
private:
std::vector<unsigned int> indices;
std::vector<glm::vec3> vertices;
std::vector<glm::vec3> normals;
glm::vec3 normal;
glm::mat4 toWorld;


public:
	OBJObject(const char* filepath);

	float angle;

	void parse(const char* filepath);
	void draw();

	void update();
	void spin(float);
};

#endif