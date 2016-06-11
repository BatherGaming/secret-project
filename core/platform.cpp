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
	double centerX = Parameters::kWheelCenterX() + 
											Parameters::kWheelRadius() * cos(angle_);
	double centerY = Parameters::kWheelCenterY() + 
											Parameters::kWheelRadius() * sin(angle_);
	Rectangle rectangle = { centerX - Parameters::kPlatformLength() / 2, 
													centerY - Parameters::kPlatformWidth() / 2,
													centerX + Parameters::kPlatformLength() / 2, 
													centerY + Parameters::kPlatformWidth() / 2 };
	Color color = {0, 0, 255};
	game->DrawRectangle(rectangle, Parameters::kPlatformDepth(), color);
}