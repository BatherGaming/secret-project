#include "platform.h"
#include "../gui/drawable.h"

Platform::Platform(size_t number, Game *game) {
	angle_ = 2 * kPI * static_cast<double>(number) / Parameters::GetInt("NumOfPlatforms");
	Draw(game);
}

void Platform::Update(size_t passed_time) {
	angle_ -= Parameters::GetInt("WheelAngVelocity") * 
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