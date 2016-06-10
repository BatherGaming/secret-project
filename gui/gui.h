#ifndef __GUI_H__
#define __GUI_H__

#include <vector>
#include <tuple>
#include <SFML/Graphics.hpp>

#include "../core/general.h"

class Gui{
private:
	std::vector<std::tuple<size_t, Rectangle, Color> > draw_queue_;
	sf::RenderWindow *window_;

	void DrawRectangle_(Rectangle rect, size_t depth, Color color);
public:
	Gui();
	~Gui();
	void DrawRectangle(Rectangle rect, size_t depth, Color color);
	void UpdateImage();
	bool RIP();
};

// __GUI_H__
#endif