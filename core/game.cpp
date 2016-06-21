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
		auto time_passed = std::chrono::duration_cast<std::chrono::nanoseconds>(
																			cur_time - last_time).count();
		for (auto key : pressed_keys) {
			switch(key){
				case upPlayer1:{
					players_[0]->Jump();
					break;
				}
				case leftPlayer1:{
					players_[0]->MoveLeft(time_passed);
					break;
				}
				case rightPlayer1:{
					players_[0]->MoveRight(time_passed);
					break;
				}
				case shootPlayer1:{
					players_[0]->Shoot(time_passed);
					break;
				}
				case upPlayer2:{
					players_[1]->Jump();
					break;
				}
				case leftPlayer2:{
					players_[1]->MoveLeft(time_passed);
					break;
				}
				case rightPlayer2:{
					players_[1]->MoveRight(time_passed);
					break;
				}
				case shootPlayer2:{
					players_[1]->Shoot(time_passed);
					break;
				}
			}
		}
		background_->Update();
		background_->Draw(this);
		for (auto platform : platforms_) {
			platform->Update(time_passed);
			platform->Draw(this);
		}
		for (auto player : players_) {
			player->Update(time_passed);
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