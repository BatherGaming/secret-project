#include "game.h"
#include <iostream> // For debug purposes

Game::Game(Gui *gui) : gui_(gui) {
	background_ = new Background(this);
	for (size_t i = 0; i < Parameters::kNumOfPlatforms(); i++) {
		platforms_.push_back(new Platform(i, this));
	}
	for (size_t i = 0; i < Parameters::kNumOfPlayers(); i++) {
		players_.push_back(new Player(this));
	}
	gui_->UpdateImage();
}

void Game::Play() {
	auto last_time = std::chrono::high_resolution_clock::now();
	while(true) {
		auto cur_time = std::chrono::high_resolution_clock::now();

		std::vector<PressedKey> pressed_keys = gui_->GetPressedKeys();
		for (auto key : pressed_keys) {
			if (key == leftPlayer1) {
				players_[0]->MoveLeft(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			}
			if (key == rightPlayer1) {
				players_[0]->MoveRight(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			}
		}
		background_->Update();
		background_->Draw(this);
		for (auto platform : platforms_) {
			platform->Update(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			platform->Draw(this);
		}
		for (auto player : players_) {
			player->Update();
			player->Draw(this);
		}
		last_time = cur_time;
		gui_->UpdateImage();
		if(gui_->RIP()){
			break;
		}
	}
};

Gui *Game::GetGui() {
	return gui_;
}

Platform *Game::GetPlatform(size_t num) {
	return platforms_[num];
}