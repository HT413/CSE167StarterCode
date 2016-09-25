#pragma once

#include <iostream>

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <OpenGL/gl.h>
#endif /* __APPLE__ */
#include <OpenGL/glext.h>

#include <GLFW/glfw3.h>
#include "Cube.h"

class Window
{
public:
	static int width;
	static int height;
	static void initialize_objects();
	static void clean_up();
	static GLFWwindow* create_window(int width, int height);
	static void resize_callback(GLFWwindow* window, int width, int height);
	static void idle_callback();
	static void display_callback(GLFWwindow*);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};
