#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "general.h"
#include "game.h"

class Platform {
private:
	double angle_;
public:
	Platform(size_t number, Game *game);
	void Update(size_t passed_time);
	void Draw(Game *game);
};

#endif