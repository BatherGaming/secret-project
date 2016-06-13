#include "background.h"
#include <iostream> // For debug purposes.

Background::Background(Game *game) {
	Draw(game);
}

void Background::Update() {
}

void Background::Draw(Game *game) {
	Rectangle rectangle = {-Parameters::kMaxCoordinate(), 
													-Parameters::kMaxCoordinate(),
													Parameters::kMaxCoordinate(), 
													Parameters::kMaxCoordinate()
												};
	Color color = {255, 255, 255};
	game->GetGui()->DrawRectangle(rectangle, Parameters::kBackgroundDepth(), color);

	std::pair<double, double> obj_size = game->GetGui()->GetObjectSize(0);


	Point tree_position = {obj_size.first / 2, -1 + obj_size.second / 2};
	game->GetGui()->DrawObject(0, Parameters::kBackgroundDepth()+1, tree_position);
	tree_position = {-obj_size.first / 2, -1 + obj_size.second / 2};
	game->GetGui()->DrawObject(0, Parameters::kBackgroundDepth()+1, tree_position);
	tree_position = {-1+obj_size.first / 2, -1 + obj_size.second / 2};
	game->GetGui()->DrawObject(0, Parameters::kBackgroundDepth()+1, tree_position);
	tree_position = {1-obj_size.first / 2, -1 + obj_size.second / 2};
	game->GetGui()->DrawObject(0, Parameters::kBackgroundDepth()+1, tree_position);
}
