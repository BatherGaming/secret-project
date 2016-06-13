#include "../gui/gui.h"
#include "game.h"

#include <iostream>

int main(){
	Gui *gui = new Gui();
	Game *game = new Game(gui);
	game->Play();
}