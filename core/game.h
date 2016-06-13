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
 	Gui *GetGui();
 	Platform *GetPlatform(size_t num);
 	void Play();
 };

#endif
