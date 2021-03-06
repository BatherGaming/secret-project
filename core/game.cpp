#include "game.h"
#include <iostream> // For debug purposes

Game::Game(Gui *gui) : gui_(gui) {
	background_ = new Background(this);
	for (size_t i = 0; i < Parameters::GetInt("NumOfPlatforms"); i++) {
		platforms_.push_back(new Platform(i, this));
	}
	Color player_colors[2] = {{255, 0, 255}, {255, 255, 0}};
	for (size_t i = 0; i < Parameters::GetInt("NumOfPlayers"); i++) {
		players_.push_back(new Player(player_colors[i], this));
	}
	gui_->UpdateImage();
}

void Game::Play() {
	auto last_time = std::chrono::high_resolution_clock::now();
	while(true) {
		auto cur_time = std::chrono::high_resolution_clock::now();

		std::vector<PressedKey> pressed_keys = gui_->GetPressedKeys();
		for (auto key : pressed_keys) {
			if (key == upPlayer1) {
				players_[0]->Jump();
			}
			if (key == leftPlayer1) {
				players_[0]->MoveLeft(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			}
			if (key == rightPlayer1) {
				players_[0]->MoveRight(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			}
			if (key == upPlayer2) {
				players_[1]->Jump();
			}
			if (key == leftPlayer2) {
				players_[1]->MoveLeft(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			}
			if (key == rightPlayer2) {
				players_[1]->MoveRight(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			}
		}
		background_->Update();
		background_->Draw(this);
		for (auto platform : platforms_) {
			platform->Update(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			platform->Draw(this);
		}
		for (auto player : players_) {
			player->Update(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			player->Draw();
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

std::vector<Platform*>& Game::GetPlatforms() {
	return platforms_;
}