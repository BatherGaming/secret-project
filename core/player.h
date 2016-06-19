#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "general.h"
#include "game.h"
#include "platform.h"

class Player {
 public:
	Player(Color color, Game *game);
	void Draw();
	void Update(size_t passed_time);
	void MoveLeft(size_t passed_time);
	void MoveRight(size_t passed_time);
	void CheckFreeFall();
	void FreeFall(double initial_speed = 0);
	void Jump();
 private:
 	Game *game_;
 	Color color_;
 	bool on_platform_;
 	int fall_state_;
	Platform *platform_;
	double shift_;

	Point location_;
	double vertical_speed_;

	void GetOnPlatform(Platform *platform);
	void CheckCollisions(size_t passed_time);
	bool SegmentsIntersect(double ax1, double ax2, double bx1, double bx2);
};

double HorizontalSpeed(size_t passed_time);

#endif 