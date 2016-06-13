#include "player.h"

Player::Player(Game *game) {
	on_platform_ = true;
	platform_ = game->GetPlatform(rand() % Parameters::kNumOfPlatforms());
	shift_ = 0.;
	Draw(game);
}

void Player::Update() {

}

void Player::Draw(Game *game) {
	Point platform_center = platform_->GetCenter();
	Rectangle rectangle = { platform_center.x + shift_ - 
																							Parameters::kPlayerLength() / 2,
													platform_center.y + Parameters::kPlatformWidth() / 2,
													platform_center.x + shift_ +
																							Parameters::kPlayerLength() / 2,
													platform_center.y + Parameters::kPlatformWidth() / 2
																						+ Parameters::kPlayerLength()
												};
	Color color = {255, 0, 255};
	game->GetGui()->DrawRectangle(rectangle, Parameters::kPlayerDepth(), color);
}

void Player::MoveLeft(size_t passed_time) {
	shift_ -= Parameters::kPlayerHorizontalSpeed() * 
							static_cast<double>(passed_time) / 1000000000;
}

void Player::MoveRight(size_t passed_time) {
	shift_ += Parameters::kPlayerHorizontalSpeed() * 
							static_cast<double>(passed_time) / 1000000000;
}