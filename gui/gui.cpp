#include <tuple>
#include <iostream> // For debug purposes.

#include <SFML/Graphics.hpp>
#include "gui.h"
#include "../core/general.h"


Gui::Gui(){
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;	

  //window_ = new (sf::RenderWindow)(
  //		sf::VideoMode(Parameters::kWindowWidth(), Parameters::kWindowHeight()), 
//  		"Secret project", sf::Style::Titlebar | sf::Style::Close, settings);
  window_ = new (sf::RenderWindow)(
  		sf::VideoMode::getFullscreenModes()[0], 
  		"Secret project", sf::Style::Fullscreen, settings);

  window_width_ = window_->getSize().x;
  window_height_ = window_->getSize().y;

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

void Gui::Draw_(const Rectangle &rect){
	sf::ConvexShape draw_rect;

	draw_rect.setPointCount(4);
	draw_rect.setFillColor(sf::Color(rect.color.red, 
																	 rect.color.green, 
																	 rect.color.blue));
	draw_rect.setPoint(0, sf::Vector2f(rect.x1, rect.y1));
	draw_rect.setPoint(1, sf::Vector2f(rect.x1, rect.y2));
	draw_rect.setPoint(2, sf::Vector2f(rect.x2, rect.y2));
	draw_rect.setPoint(3, sf::Vector2f(rect.x2, rect.y1));

	window_->draw(draw_rect);
}
void Gui::Draw_(const Image &img){
	sf::Sprite object_sprite;
	sf::Texture object_texture = object_textures_[img.obj_id];
	object_sprite.setTexture(object_texture, true);
	object_sprite.setPosition(img.location.x - object_texture.getSize().x / 2, 
														img.location.y - object_texture.getSize().y / 2);
	window_->draw(object_sprite);
}


void Gui::Draw(Drawable *drawable){
	draw_queue_.push_back(drawable);
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

	sort(draw_queue_.begin(), draw_queue_.end(),
		   [](Drawable *a, Drawable *b){ return a->depth() < b->depth(); });

	for(auto& drawable : draw_queue_){
		drawable->Draw(this);
	}

	draw_queue_.clear();

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

Point Gui::ConvertCoordinates(double x, double y){
	return Point((x + 1) * window_width_ / 2, (1 - y) * window_height_ / 2);
}
