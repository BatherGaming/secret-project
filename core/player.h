#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "general.h"
#include "game.h"
#include "platform.h"

class Player {
 public:
	Player(Game *game);
	void Draw(Game *game);
	void Update();
	void MoveLeft(size_t passed_time);
	void MoveRight(size_t passed_time);
 private:
 	bool on_platform_;
	Platform *platform_;
	double shift_;
};

#endif 