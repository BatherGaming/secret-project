#include "drawable.h"
#include "gui.h"

size_t Drawable::depth(){
	return depth_;
}

void Rectangle::Draw(Gui *gui){
	gui->Draw_(*this);
}
void Image::Draw(Gui *gui){
	gui->Draw_(*this);
}

Rectangle::Rectangle(double _x1, double _y1, double _x2, double _y2,
 		Color _color, size_t depth, Gui *gui):Drawable(depth), color(_color){

	Point bottom_left_corner = gui->ConvertCoordinates(_x1, _y1);
	Point upper_right_corner = gui->ConvertCoordinates(_x2, _y2);
	x1 = bottom_left_corner.x;
	x2 = upper_right_corner.x;
	y1 = bottom_left_corner.y;
	y2 = upper_right_corner.y;
}

Image::Image(size_t _obj_id, Point _location, size_t _depth,
						 Gui *gui):Drawable(_depth), obj_id(_obj_id),
											 location(gui->ConvertCoordinates(_location.x, 
											 																	_location.y)){}
