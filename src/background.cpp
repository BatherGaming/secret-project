#include "background.h"

Background::Background(Game *game) {
	Draw(game);
}

void Background::Update() {
}

void Background::Draw(Game *game) {
	Rectangle rectangle = {-kMaxCoordinate, -kMaxCoordinate,
													kMaxCoordinate, kMaxCoordinate};
	Color color = {255, 0, 0};
	game->DrawRectangle(rectangle, kBackgroundDepth, color);
}
