#ifndef __GUI_H__
#define __GUI_H__

#include <vector>
#include <tuple>
#include <string>
#include <SFML/Graphics.hpp>

#include "../core/general.h"
#include "general.h"
#include "drawable.h"

class Gui{
private:
	std::vector<Drawable*> draw_queue_;
	std::vector<sf::Texture> object_textures_;
	
	int window_width_;
	int window_height_;

	void LoadObjectTextures();
public:
	Point ConvertCoordinates(double x, double y);

	sf::RenderWindow *window_;
	Gui();
	~Gui();

	void Draw_(const Rectangle &rect);
	void Draw_(const Image &img);

	std::vector<PressedKey> GetPressedKeys();
	void Draw(Drawable *drawable);
	std::pair<double, double> GetObjectSize(size_t obj_id);
	void UpdateImage();
	bool RIP();


};

// __GUI_H__
#endif