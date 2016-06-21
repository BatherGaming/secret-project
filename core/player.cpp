#include <iostream> // For debug purposes.
#include <cmath>

#include "player.h"
#include "../gui/drawable.h"


Player::Player(Color color, Game *game) : color_(color), game_(game) {
	horizontal_speed_ = vertical_speed_ = 0;
	on_platform_ = true;
	platform_ = game_->GetPlatforms()[rand() % Parameters::GetInt("NumOfPlatforms")];
	fall_state_ = 0;
	shift_ = 0.;
	Draw();
}

void Player::Update(size_t passed_time) {
	previous_location_ = location_;
	double real_time = static_cast<double>(passed_time) / 1000000000;

	if(fabs(horizontal_speed_) > epsilon) {
		if(on_platform_){
			shift_ += horizontal_speed_ * real_time;
		}
		else{
			location_.x += horizontal_speed_ * real_time;
		}
	}

	if (on_platform_) { 
		Point platform_center = platform_->GetCenter();
		location_.x = platform_center.x + shift_;
		location_.y = platform_center.y + Parameters::GetDbl("PlatformWidth") / 2 +
												Parameters::GetDbl("PlayerLength") / 2;
		if (!fall_state_) { 
			return; 
		}
		else if(fall_state_ == 1){
			FreeFall();
			fall_state_ = 0;
		}
		else if(fall_state_ == 2){
			FreeFall(Parameters::GetDbl("PlayerJumpSpeed"));
			fall_state_ = 0;
		}
	}
	location_.y += vertical_speed_ * real_time + real_time * real_time * 
										Parameters::GetDbl("VerticalAcceleration") / 2;
	vertical_speed_ += Parameters::GetDbl("VerticalAcceleration") * real_time;

	// Make the guy appear at the top when falling to low
	if(location_.y <= -Parameters::GetDbl("MaxCoordinate")){ 
		location_.y = Parameters::GetDbl("MaxCoordinate");
	}

	if(vertical_speed_ < 0){
		CheckCollisions();
	}
}

void Player::CheckCollisions(){
	std::vector<Platform*> platforms = game_->GetPlatforms();
	for(auto platform : platforms){
		Point center = platform->GetCenter();
		if(SegmentsIntersect(location_.x - Parameters::GetDbl("PlayerLength")/2,
													location_.x + Parameters::GetDbl("PlayerLength")/2,
													center.x - Parameters::GetDbl("PlatformLength")/2,
													center.x + Parameters::GetDbl("PlatformLength")/2) &&
			 SegmentsIntersect(location_.y - Parameters::GetDbl("PlayerLength")/2,
													location_.y + Parameters::GetDbl("PlayerLength")/2,
													center.y - Parameters::GetDbl("PlatformWidth")/2,
													center.y + Parameters::GetDbl("PlatformWidth")/2) &&
			 previous_location_.y - Parameters::GetDbl("PlayerLength") / 2 > 
			 platform->GetPreviousCenter().y + Parameters::GetDbl("PlatformWidth")/2){
			GetOnPlatform(platform);
			break;
		}
	}
}
void Player::GetOnPlatform(Platform *platform){
	platform_ = platform;
	on_platform_ = true;
	Point platform_center = platform->GetCenter();
	shift_ = location_.x - platform_center.x;
	location_.y = platform_center.y + Parameters::GetDbl("PlayerLength")/2
								+ Parameters::GetDbl("PlatformWidth")/2;
	vertical_speed_ = 0;
	fall_state_ = 0;
}

void Player::Draw() {
	Drawable *rectangle = new Rectangle(location_.x - 
																					Parameters::GetDbl("PlayerLength") / 2,
													location_.y - Parameters::GetDbl("PlayerLength") / 2,
													location_.x + Parameters::GetDbl("PlayerLength") / 2,
													location_.y + Parameters::GetDbl("PlayerLength") / 2,
													color_,
													Parameters::GetInt("PlayerDepth"),
													game_->GetGui()
													);						
	game_->GetGui()->Draw(rectangle);
}

double HorizontalShift(int passed_time) {
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
		fall_state_ = true;
	}
}

void Player::MoveLeft(int passed_time) {
	// Be careful here.
	//std::cerr << "kek" << std::endl;
	MoveRight(-passed_time);
	direction_ = left;
}

void Player::MoveRight(int passed_time) {
	direction_ = right;
	double delta;
	if(fabs(horizontal_speed_) > epsilon){
		delta = Parameters::GetDbl("PlayerHorizontalAccel") * 
							static_cast<double>(passed_time) / 1000000000;
		if(horizontal_speed_ * (horizontal_speed_ + delta) < 0){
			delta += horizontal_speed_;
			horizontal_speed_ = 0;
		} 
		else{
			horizontal_speed_ += delta;
			delta = 0;
		}
	}
	else{
		delta = HorizontalShift(passed_time);
	}


	if (on_platform_) {
		shift_ += delta;
		CheckFreeFall();
	}
	else {
		location_.x += delta;
	}
}
void Player::Jump(){
	fall_state_ = 2;
}
void Player::Shoot(size_t passed_time){
	if(direction_ == left)
		horizontal_speed_ = Parameters::GetDbl("ImpactSpeed");
	else
		horizontal_speed_ = -Parameters::GetDbl("ImpactSpeed");
}

bool Player::SegmentsIntersect(double ax1, double ax2, double bx1, double bx2){
	return ax1 <= bx2 && bx1 <= ax2;
}