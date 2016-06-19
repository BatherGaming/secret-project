#include <iostream> // For debug purposes.
#include <cmath>

#include "player.h"
#include "../gui/drawable.h"


Player::Player(Color color, Game *game) : color_(color) {
	on_platform_ = true;
	platform_ = game->GetPlatform(rand() % Parameters::GetInt("NumOfPlatforms"));
	shift_ = 0.;
	Draw(game);
}

void Player::Update(size_t passed_time) {
	if (on_platform_) { 
		Point platform_center = platform_->GetCenter();
		location_.x = platform_center.x + shift_;
		location_.y = platform_center.y + Parameters::GetDbl("PlatformWidth") / 2 +
												Parameters::GetDbl("PlayerLength") / 2;
		if (!NeedToFall_) { 
			return; 
		}
		else {
			FreeFall();
			NeedToFall_ = false;
		}
	}
	double real_time = static_cast<double>(passed_time) / 1000000000;
	location_.y += vertical_speed_ * real_time + real_time * real_time * 
										Parameters::GetDbl("VerticalAcceleration") / 2;
	vertical_speed_ += Parameters::GetDbl("VerticalAcceleration") * real_time;

}

void Player::Draw(Game *game) {
	Drawable *rectangle = new Rectangle(location_.x - 
																					Parameters::GetDbl("PlayerLength") / 2,
													location_.y - Parameters::GetDbl("PlayerLength") / 2,
													location_.x + Parameters::GetDbl("PlayerLength") / 2,
													location_.y + Parameters::GetDbl("PlayerLength") / 2,
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

void Player::FreeFall(double initial_speed) {
//	location_.x = platform_->GetCenter().x + shift_;
//	location_.y = platform_->GetCenter().y + Parameters::GetDbl("PlatformWidth") / 2 + 
																				 //+ Parameters::GetDbl("PlayerLength") / 2;
	vertical_speed_ = initial_speed - cos(platform_->GetAngle()) * 
																		Parameters::GetDbl("WheelAngVelocity")*
																		Parameters::GetDbl("WheelRadius");
	on_platform_ = false;
	platform_ = nullptr;
}

void Player::CheckFreeFall() {
	if (fabs(shift_) > Parameters::GetDbl("PlatformLength") / 2 + 
										Parameters::GetDbl("PlayerLength") / 2) {
		std::cerr << fabs(shift_) << " " << Parameters::GetDbl("PlatformLength") / 2 + 
										Parameters::GetDbl("PlayerLength") / 2 << std::endl;
		NeedToFall_ = true;
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