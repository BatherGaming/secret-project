#ifndef __GAME_H__
#define __GAME_H__

#include "general.h"
#include "background.h"
#include "platform.h"
#include "player.h"
#include "gui.h"

class Game {
 private:
 	const size_t kNumOfPlatforms = 10;
 	const size_t kNumOfPlayers = 2;
	Gui *gui_;
 	Background *background_;
 	std::vector<Platform*> platforms_;
 	std::vector<Player*> players_;
 public:
 	Game(Gui *gui);
 	void Play();
};

#endif
