#ifndef __GUI_H__
#define __GUI_H__

#include "general.h"

class Gui {
public:
	void DrawRectangle(Rectangle rectangle, size_t depth, Color color) {
		std::cout << "Rectangle: " << "x1:" << rectangle.x1 << " y1:" << rectangle.y1 
							<< "x2:" << rectangle.x2 << " y2:" << rectangle.y2 
							<< std::endl;
		std::cout << "depth: " << depth << std::endl;
		std::cout << "color: " << "R:" << color.red << " G:" << color.green << " B:"
							<< color.blue << std::endl;
	}
	void UpdateImage() {
		std::cout << "UpdateImage" << std::endl;
	}
};

#endif