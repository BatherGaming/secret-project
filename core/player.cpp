#include "player.h"
#include "../gui/drawable.h"


Player::Player(Color color, Game *game) : color_(color) {
	on_platform_ = true;
	platform_ = game->GetPlatform(rand() % Parameters::GetInt("NumOfPlatforms"));
	shift_ = 0.;
	Draw(game);
}

void Player::Update(size_t passed_time) {
	if (on_platform_) { return; }
	double real_time = static_cast<double>(passed_time) / 1000000000;
	location_.y -= vertical_speed * real_time + real_time * real_time * 
										Parameters::GetDbl("VerticalAcceleration");
									
}

void Player::Draw(Game *game) {
	Point platform_center = platform_->GetCenter();
	Drawable *rectangle = new Rectangle(platform_center.x + shift_ - 
																							Parameters::GetDbl("PlayerLength") / 2,
													platform_center.y + Parameters::GetDbl("PlatformWidth") / 2,
													platform_center.x + shift_ +
																							Parameters::GetDbl("PlayerLength") / 2,
													platform_center.y + Parameters::GetDbl("PlatformWidth") / 2
																						+ Parameters::GetDbl("PlayerLength"),
																						color_,
																						Parameters::GetInt("PlayerDepth"),
																						game->GetGui()
																						);						
	game->GetGui()->Draw(rectangle);
}

double HorizontalShift(size_t passed_time) {
	return Parameters::GetDbl("PlayerHorizontalSpeed") * 
							static_cast<double>(passed_time) / 1000000000;
}

void Player::FreeFall(double initial_speed = 0) {
	location_.x = platform_->GetCenter().x + shift_;
	location_.y = platform_->GetCenter().y + Parameters::GetDbl("PlatformWidth") / 2 + 
																				 + Parameters::GetDbl("PlayerLength") / 2;
	vertical_speed = initial_speed;
	on_platform_ = false;
	platform_ = nullptr;
}

void Player::CheckFreeFall() {
	if (abs(shift_) > Parameters::GetDbl("PlatfromLength") / 2 + 
										Parameters::GetDbl("PlayerLength") / 2) {
		FreeFall();
	}
}

void Player::MoveLeft(size_t passed_time) {
	if (on_platform_) {
		shift_ -= HorizontalShift(passed_time);
		CheckFreeFall();
	} 
	else {
		location_.x -= HorizontalShift(passed_time); 
	}
}

void Player::MoveRight(size_t passed_time) {
	if (on_platform_) {
		shift_ += HorizontalShift(passed_time);
		CheckFreeFall();
	}
	else {
		location_.x += HorizontalShift(passed_time);
	}
}