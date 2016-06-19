#include "platform.h"
#include "../gui/drawable.h"

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
	Color color = {0, 0, 255};
	Drawable *rectangle = new Rectangle( center.x - Parameters::kPlatformLength() / 2, 
													center.y - Parameters::kPlatformWidth() / 2,
													center.x + Parameters::kPlatformLength() / 2, 
													center.y + Parameters::kPlatformWidth() / 2,
													color,
													Parameters::kPlatformDepth(),
													game->GetGui()
												);
	game->GetGui()->Draw(rectangle);
}

Point Platform::GetCenter() {
	return { Parameters::kWheelCenterX() + Parameters::kWheelRadius() * cos(angle_),
					 Parameters::kWheelCenterY() + Parameters::kWheelRadius() * sin(angle_)
				};
}