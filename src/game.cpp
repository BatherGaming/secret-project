#include "game.h"

Game::Game(Gui *gui) : gui_(gui) {
	background_ = new Background();
	for (size_t i = 0; i < kNumOfPlatforms; i++) {
		platforms_.push_back(new Platform());
	}
	for (size_t i = 0; i < kNumOfPlayers; i++) {
		players_.push_back(new Player());
	}
}