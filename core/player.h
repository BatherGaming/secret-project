#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "general.h"
#include "game.h"
#include "platform.h"

class Player {
 public:
	Player(Color color, Game *game);
	void Draw(Game *game);
	void Update(size_t passed_time);
	void MoveLeft(size_t passed_time);
	void MoveRight(size_t passed_time);
	void CheckFreeFall();
	void FreeFall(double initial_speed = 0);
 private:
 	Color color_;
 	bool on_platform_;
	Platform *platform_;
	double shift_;

	Point location_;
	double vertical_speed_;


};

double HorizontalSpeed(size_t passed_time);

#endif 