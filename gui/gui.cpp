#include <tuple>
#include <iostream> // For debug purposes.

#include <SFML/Graphics.hpp>
#include "gui.h"
#include "../core/general.h"


Gui::Gui(){
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;	

  window_ = new (sf::RenderWindow)(
  		sf::VideoMode(Parameters::kWindowWidth(), Parameters::kWindowHeight()), 
  		"SFML works!", sf::Style::Titlebar | sf::Style::Close, settings);

  window_width_ = Parameters::kWindowWidth();
  window_height_ = Parameters::kWindowHeight();

  LoadObjectTextures();
}
Gui::~Gui(){
}
std::pair<double, double> Gui::GetObjectSize(size_t obj_id){
	return std::make_pair(2.0 * object_textures_[obj_id].getSize().x / 
																																window_width_, 
									 			2.0 * object_textures_[obj_id].getSize().y /
									 																							window_height_);
}
void Gui::LoadObjectTextures(){
	std::ifstream in (kObjectTexturePathsFile);
	size_t texture_id;
	std::string texture_path;
	while(in >> texture_id >> texture_path){
		sf::Image texture_image;
		texture_image.loadFromFile(texture_path);
		sf::Texture texture;
		texture.loadFromImage(texture_image);
		object_textures_.push_back(texture);
	}
	in.close();
	std::cerr << "Textures number: " << object_textures_.size() << std::endl;
}

void Gui::DrawRectangle_(Rectangle rect, Color color){
	sf::ConvexShape draw_rect;

	draw_rect.setPointCount(4);
	draw_rect.setFillColor(sf::Color(color.red, color.green, color.blue));
	draw_rect.setPoint(0, sf::Vector2f(rect.x1, rect.y1));
	draw_rect.setPoint(1, sf::Vector2f(rect.x1, rect.y2));
	draw_rect.setPoint(2, sf::Vector2f(rect.x2, rect.y2));
	draw_rect.setPoint(3, sf::Vector2f(rect.x2, rect.y1));

	window_->draw(draw_rect);
}
void Gui::DrawObject_(size_t object_id, Point position){
	sf::Sprite object_sprite;
	sf::Texture object_texture = object_textures_[object_id];
	object_sprite.setTexture(object_texture, true);
	object_sprite.setPosition(position.x - object_texture.getSize().x / 2, 
														position.y - object_texture.getSize().y / 2);
	window_->draw(object_sprite);
}

void Gui::DrawRectangle(Rectangle rect, size_t depth, Color color){
	std::pair<double, double> bottom_left_corner = ConvertCoordinates(rect.x1, 
																																		rect.y1);
	std::pair<double, double> upper_right_corner = ConvertCoordinates(rect.x2, 
																																		rect.y2);
	rect.x1 = bottom_left_corner.first;
	rect.x2 = upper_right_corner.first;
	rect.y1 = bottom_left_corner.second;
	rect.y2 = upper_right_corner.second;
	draw_rect_queue_.push_back(std::make_tuple(depth, rect, color));
}

void Gui::DrawObject(size_t obj_id, size_t depth, Point position){
	std::pair<double, double> position_converted = ConvertCoordinates(position.x, 
																																		position.y);
	position.x = position_converted.first;
	position.y = position_converted.second;
	draw_obj_queue_.push_back(std::make_tuple(depth, obj_id, position));
}

// TODO: Rename and refactor.
bool cmpRect( const std::tuple<size_t, Rectangle, Color> &a, 
					const std::tuple<size_t, Rectangle, Color> &b){
	return std::get<0>(a) < std::get<0>(b);
}
bool cmpObj( const std::tuple<size_t, size_t, Point> &a, 
					const std::tuple<size_t, size_t, Point> &b){
	return std::get<0>(a) < std::get<0>(b);
}

void Gui::UpdateImage(){
	window_->clear();

	// TODO: Merge into one vector.

	sort(draw_rect_queue_.begin(), draw_rect_queue_.end(), cmpRect);
	for(auto &rect : draw_rect_queue_){
		DrawRectangle_(std::get<1>(rect), std::get<2>(rect));
	}
	draw_rect_queue_.clear();

	sort(draw_obj_queue_.begin(), draw_obj_queue_.end(), cmpObj);
	for(auto &obj : draw_obj_queue_){
		DrawObject_(std::get<1>(obj), std::get<2>(obj));
	}
	draw_obj_queue_.clear();

	window_->display();
}

bool Gui::RIP(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		return true;
	}
  sf::Event event;
  while (window_->pollEvent(event))
  {
    if (event.type == sf::Event::Closed){
      window_->close();
      return true;
    }
  }
  return false;
}

std::vector<PressedKey> Gui::GetPressedKeys(){
	std::vector<PressedKey> pressed_keys;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		pressed_keys.push_back(PressedKey::leftPlayer1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		pressed_keys.push_back(PressedKey::rightPlayer1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		pressed_keys.push_back(PressedKey::upPlayer1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		pressed_keys.push_back(PressedKey::leftPlayer2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		pressed_keys.push_back(PressedKey::rightPlayer2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		pressed_keys.push_back(PressedKey::upPlayer2);
	}
	return pressed_keys;
}

std::pair<double, double> Gui::ConvertCoordinates(double x, double y){
	return std::make_pair((x + 1) * window_width_ / 2, (1 - y) * window_height_ / 2);
}
