#include "platform.h"

Platform::Platform(size_t number, Game *game) {
	angle_ = 2 * kPI * static_cast<double>(number) / Parameters::kNumOfPlatforms();
	Draw(game);
}

void Platform::Update(size_t passed_time) {
	angle_ -= Parameters::kWheelAngVelocity() * 
							static_cast<double>(passed_time) / 1000000000;
	while (angle_ < 0)
		angle_ += 2 * kPI;
}

void Platform::Draw(Game *game) {
	Point center = GetCenter();
	Rectangle rectangle = { center.x - Parameters::kPlatformLength() / 2, 
													center.y - Parameters::kPlatformWidth() / 2,
													center.x + Parameters::kPlatformLength() / 2, 
													center.y + Parameters::kPlatformWidth() / 2 
												};
	Color color = {0, 0, 255};
	game->GetGui()->DrawRectangle(rectangle, Parameters::kPlatformDepth(), color);
}

Point Platform::GetCenter() {
	return { Parameters::kWheelCenterX() + Parameters::kWheelRadius() * cos(angle_),
					 Parameters::kWheelCenterY() + Parameters::kWheelRadius() * sin(angle_)
				};
}