#include "gui.h"
#include "game.h"

int main(){
	Gui *gui = new Gui();
	Game *game = new Game(gui);
	game->Play();

}