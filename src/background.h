#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "general.h"
#include "game.h"

class Background {
public:
	Background(Game *game);
	void Update();
	void Draw(Game *game);
};

#endif