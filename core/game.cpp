#include "game.h"
#include <iostream> // For debug purposes

Game::Game(Gui *gui) : gui_(gui) {
	background_ = new Background(this);
	for (size_t i = 0; i < Parameters::kNumOfPlatforms(); i++) {
		platforms_.push_back(new Platform(i, this));
	}
	for (size_t i = 0; i < Parameters::kNumOfPlayers(); i++) {
		players_.push_back(new Player());
	}
	gui_->UpdateImage();
}

void Game::Play() {
	auto last_time = std::chrono::high_resolution_clock::now();
	while(true) {
		auto cur_time = std::chrono::high_resolution_clock::now();
		background_->Update();
		background_->Draw(this);
		for (auto platform : platforms_) {
			platform->Update(std::chrono::duration_cast<std::chrono::nanoseconds>(cur_time - last_time).count());
			platform->Draw(this);
		}
		last_time = cur_time;
		gui_->UpdateImage();
		if(gui_->RIP()){
			break;
		}
	}
};

void Game::DrawRectangle(Rectangle rectangle, size_t depth, Color color) {
	gui_->DrawRectangle(rectangle, depth, color);
}
void Game::DrawObject(size_t obj_id, size_t depth, Point position){
	gui_->DrawObject(obj_id, depth, position);
}
std::pair<double,double> Game::GetObjectSize(size_t obj_id){
	return gui_->GetObjectSize(obj_id);
}