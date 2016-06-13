#ifndef __GUI_H__
#define __GUI_H__

#include <vector>
#include <tuple>
#include <string>
#include <SFML/Graphics.hpp>

#include "../core/general.h"

class Gui{
private:
	std::vector<std::tuple<size_t, Rectangle, Color> > draw_rect_queue_;
	std::vector<std::tuple<size_t, size_t, Point> > draw_obj_queue_;
	std::vector<sf::Texture> object_textures_;
	
	int window_width_;
	int window_height_;

	void DrawRectangle_(Rectangle rect, Color color);
	void DrawObject_(size_t object_id, Point position);

	std::pair<double, double> ConvertCoordinates(double x, double y);
	void LoadObjectTextures();
public:
	sf::RenderWindow *window_;
	Gui();
	~Gui();

	std::vector<PressedKey> GetPressedKeys();
	void DrawRectangle(Rectangle rect, size_t depth, Color color);
	void DrawObject(size_t obj_id, size_t depth, Point position);
	std::pair<double, double> GetObjectSize(size_t obj_id);
	void UpdateImage();
	bool RIP();


};

// __GUI_H__
#endif