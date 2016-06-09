#ifndef _GUI_H_
#define _GUI_H_

#include "general.h"

class Gui{
private:
	vector<pair<size_t, Rectangle> > draw_query_;

	GLFWwindow* window_;
	GLuint VertexArrayID;
	GLuint programID_;
public:
	Gui();
	~Gui();
	void DrawRectangle(Rectangle rect, size_t depth, Color color);
	void DrawTriangle();
	void UpdateImage();
};

// _GUI_H_
#endif