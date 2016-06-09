#include "game.h"

Game::Game(Gui *gui) : gui_(gui) {
	background_ = new Background(this);
	for (size_t i = 0; i < kNumOfPlatforms; i++) {
		platforms_.push_back(new Platform(i, this));
	}
	for (size_t i = 0; i < kNumOfPlayers; i++) {
		players_.push_back(new Player());
	}
	gui_->UpdateImage();
}

void Game::Play() {
	size_t last_time = 0;
	for (;;) {
		size_t cur_time = clock();
		background_->Update();
		background_->Draw(this);
		for (auto platform : platforms_) {
			platform->Update(cur_time - last_time);
			platform->Draw(this);
		}
		last_time = cur_time;
		gui_->UpdateImage();
	}
};

void Game::DrawRectangle(Rectangle rectangle, size_t depth, Color color) {
	gui_->DrawRectangle(rectangle, depth, color);
}