#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include "general.h"
#include "gui.h"


class Drawable{
 private:
	size_t depth_;
 public:
 	Drawable(size_t _depth):depth_(_depth){}
	virtual void Draw(Gui *gui) = 0;
	size_t depth();
};

struct Point {
	double x;
	double y;
	Point(){}
	Point(double _x, double _y):x(_x), y(_y){}
};
struct Color {
	int red;
	int green;
	int blue;
};
class Rectangle : public Drawable{
 public:
 	Rectangle(double x1, double y1, double x2, double y2,
 						Color color, size_t depth, Gui *gui);
 	void Draw(Gui *gui) override;
 	double x1;
	double y1;
	double x2;
	double y2;
	Color color;
};
class Image : public Drawable{
 public:
 	Image(size_t obj_id, Point location, size_t depth, Gui *gui);
 	void Draw(Gui *gui) override;
 	size_t obj_id;
 	Point location;
};

#endif // __DRAWABLE_H__