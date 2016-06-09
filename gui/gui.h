#ifndef __GUI_H__
#define __GUI_H__

#include "../src/general.h"
#include <vector>

class Gui{
private:
	std::vector<std::pair<size_t, Rectangle> > draw_query_;

	GLFWwindow* window_;
	GLuint VertexArrayID_;
	GLuint programID_;
	void DrawRectangle_(Rectangle rect, size_t depth, Color color);
	void DrawTriangle_(std::vector<std::pair<float, float> > v, Color color);
public:
	Gui();
	~Gui();
	void DrawRectangle(Rectangle rect, size_t depth, Color color);
	void DrawTriangle(std::vector<std::pair<float, float> > v, Color color);
	void UpdateImage();
};

// __GUI_H__
#endif