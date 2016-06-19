#include "player.h"
#include "../gui/drawable.h"


Player::Player(Color color, Game *game) : color_(color) {
	on_platform_ = true;
	platform_ = game->GetPlatform(rand() % Parameters::kNumOfPlatforms());
	shift_ = 0.;
	Draw(game);
}

void Player::Update() {

}

void Player::Draw(Game *game) {
	Point platform_center = platform_->GetCenter();
	Drawable *rectangle = new Rectangle(platform_center.x + shift_ - 
																							Parameters::kPlayerLength() / 2,
													platform_center.y + Parameters::kPlatformWidth() / 2,
													platform_center.x + shift_ +
																							Parameters::kPlayerLength() / 2,
													platform_center.y + Parameters::kPlatformWidth() / 2
																						+ Parameters::kPlayerLength(),
																						color_,
																						Parameters::kPlayerDepth(),
																						game->GetGui()
																						);						
	game->GetGui()->Draw(rectangle);
}

void Player::MoveLeft(size_t passed_time) {
	shift_ -= Parameters::kPlayerHorizontalSpeed() * 
							static_cast<double>(passed_time) / 1000000000;
}

void Player::MoveRight(size_t passed_time) {
	shift_ += Parameters::kPlayerHorizontalSpeed() * 
							static_cast<double>(passed_time) / 1000000000;
}