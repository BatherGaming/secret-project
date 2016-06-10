#include <tuple>

#include <SFML/Graphics.hpp>
#include "gui.h"


Gui::Gui(){
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;	

  window_ = new (sf::RenderWindow)(sf::VideoMode(700, 700), "SFML works!", sf::Style::Default, settings);
}
Gui::~Gui(){
}

void Gui::DrawRectangle_(Rectangle rect, size_t depth, Color color){
	sf::ConvexShape draw_rect;

	draw_rect.setPointCount(4);
	draw_rect.setFillColor(sf::Color(color.red, color.green, color.blue));
	draw_rect.setPoint(0, sf::Vector2f(rect.x1, rect.y1));
	draw_rect.setPoint(1, sf::Vector2f(rect.x1, rect.y2));
	draw_rect.setPoint(2, sf::Vector2f(rect.x2, rect.y2));
	draw_rect.setPoint(3, sf::Vector2f(rect.x2, rect.y1));

	window_->draw(draw_rect);
}

void Gui::DrawRectangle(Rectangle rect, size_t depth, Color color){
	rect.x1 = (rect.x1 + 1) * 350;
	rect.x2 = (rect.x2 + 1) * 350;
	rect.y1 = (rect.y1 + 1) * 350;
	rect.y2 = (rect.y2 + 1) * 350;
	draw_queue_.push_back(std::make_tuple(depth, rect, color));
}

bool cmp( const std::tuple<size_t, Rectangle, Color> &a, 
					const std::tuple<size_t, Rectangle, Color> &b){
	return std::get<0>(a) < std::get<0>(b);
}

void Gui::UpdateImage(){
	window_->clear();

	sort(draw_queue_.begin(), draw_queue_.end(), cmp);
	for(auto &rect : draw_queue_){
		DrawRectangle_(std::get<1>(rect), std::get<0>(rect), std::get<2>(rect));
	}
	draw_queue_.clear();

	window_->display();
}

bool Gui::RIP(){
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
