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
};

#endif
