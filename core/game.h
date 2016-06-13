#ifndef __GAME_H__
#define __GAME_H__

#include "general.h"
#include "background.h"
#include "platform.h"
#include "player.h"
#include "../gui/gui.h"

class Game {
 private:
	Gui *gui_;
 	Background *background_;
 	std::vector<Platform*> platforms_;
 	std::vector<Player*> players_;
 public:
 	Game(Gui *gui);
 	void Play();
 	void DrawRectangle(Rectangle rectangle, size_t depth, Color color);
 	void DrawObject(size_t obj_id, size_t depth, Point position);
 	std::pair<double,double> GetObjectSize(size_t obj_id);
};

#endif
