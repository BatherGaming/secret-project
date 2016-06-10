#include "platform.h"

Platform::Platform(size_t number, Game *game) {
	angle_ = 2 * kPI * number / kNumOfPlatforms;
	Draw(game);
}

void Platform::Update(size_t passed_time) {
	angle_ -= kWheelAngVelocity * passed_time;
	while (angle_ < 0)
		angle_ += 2 * kPI;
}

void Platform::Draw(Game *game) {
	double centerX = kWheelCenterX + kWheelRadius * cos(angle_);
	double centerY = kWheelCenterY + kWheelRadius * sin(angle_);
	Rectangle rectangle = { centerX - kPlatformLength / 2, 
													centerY - kPlatformWidth / 2,
													centerX + kPlatformLength / 2, 
													centerY + kPlatformWidth / 2 };
	Color color = {0, 0, 255};
	game->DrawRectangle(rectangle, kPlatformDepth, color);
}