#ifndef __GUI_H__
#define __GUI_H__

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;
#include "../src/general.h"
#include <vector>

class Gui{
private:
	std::vector<std::tuple<size_t, Rectangle, Color> > draw_queue_;

	GLFWwindow* window_;
	GLuint VertexArrayID_;
	GLuint programID_;
	void DrawRectangle_(Rectangle rect, size_t depth, Color color);
	void DrawTriangle_(std::vector<std::pair<float, float> > v, Color color);
public:
	Gui();
	~Gui();
	void DrawRectangle(Rectangle rect, size_t depth, Color color);
	void UpdateImage();
};

// __GUI_H__
#endif