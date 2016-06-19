#include "background.h"
#include "../gui/drawable.h"
#include <iostream> // For debug purposes.

Background::Background(Game *game) {
	Draw(game);
}

void Background::Update() {
}

void Background::Draw(Game *game) {
	Color color = {255, 255, 255};
	Drawable *rectangle = new Rectangle(-Parameters::GetDbl("MaxCoordinate"), 
											 -Parameters::GetDbl("MaxCoordinate"),
											 Parameters::GetDbl("MaxCoordinate"), 
											 Parameters::GetDbl("MaxCoordinate"),
											 color,
											 Parameters::GetInt("BackgroundDepth"),
											 game->GetGui());
	game->GetGui()->Draw(rectangle);

	std::pair<double, double> obj_size = game->GetGui()->GetObjectSize(0);


	Point tree_position = {obj_size.first / 2, -1 + obj_size.second / 2};
	Drawable *tree = new Image(0, tree_position, Parameters::GetInt("BackgroundDepth") + 1,
					game->GetGui());
	game->GetGui()->Draw(tree);
	
	tree_position = {-obj_size.first / 2, -1 + obj_size.second / 2};
	tree = new Image(0, tree_position, Parameters::GetInt("BackgroundDepth") + 1,
					game->GetGui());
	game->GetGui()->Draw(tree);
	
	tree_position = {-1+obj_size.first / 2, -1 + obj_size.second / 2};
	tree = new Image(0, tree_position, Parameters::GetInt("BackgroundDepth") + 1,
					game->GetGui());
	game->GetGui()->Draw(tree);
	
	tree_position = {1-obj_size.first / 2, -1 + obj_size.second / 2};
	tree = new Image(0, tree_position, Parameters::GetInt("BackgroundDepth") + 1,
					game->GetGui());
	game->GetGui()->Draw(tree);
}
