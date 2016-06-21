#include <iostream> // For debug purposes.
#include "platform.h"
#include "../gui/drawable.h"

Platform::Platform(size_t number, Game *game) {
	angle_ = 2 * kPI * static_cast<double>(number) / Parameters::GetInt("NumOfPlatforms");
	previous_angle_ = angle_;
	Draw(game);
}

void Platform::Update(size_t passed_time) {
	previous_angle_ = angle_;
	angle_ -= Parameters::GetDbl("WheelAngVelocity") * 
							static_cast<double>(passed_time) / 1000000000;
	while (angle_ < 0)
		angle_ += 2 * kPI;
}

void Platform::Draw(Game *game) {
	Point center = GetCenter();
	Color color = {0, 0, 255};
	Drawable *rectangle = new Rectangle( center.x - Parameters::GetDbl("PlatformLength") / 2, 
													center.y - Parameters::GetDbl("PlatformWidth") / 2,
													center.x + Parameters::GetDbl("PlatformLength") / 2, 
													center.y + Parameters::GetDbl("PlatformWidth") / 2,
													color,
													Parameters::GetInt("PlatformDepth"),
													game->GetGui()
												);
	game->GetGui()->Draw(rectangle);
}

Point Platform::GetCenter() {
	return { Parameters::GetDbl("WheelCenterX") + Parameters::GetDbl("WheelRadius") * cos(angle_),
					 Parameters::GetDbl("WheelCenterY") + Parameters::GetDbl("WheelRadius") * sin(angle_)
				};
}
Point Platform::GetPreviousCenter(){
	std::swap(angle_, previous_angle_);
	Point result = GetCenter();
	std::swap(angle_, previous_angle_);
	return result;
}


double Platform::GetAngle() {
	return angle_;
}