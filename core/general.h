#ifndef __GENERAL_H__
#define __GENERAL_H__

#include <bits/stdc++.h>

class Game;
class Background;
class Platform;
class Player;

struct Point {double x, y; };
struct Rectangle { double x1, y1, x2, y2; };
struct Color { int red, green, blue; };

const double kPI = atan2(0., -1.);
 
class Parameters {
 private:
	static double kMaxCoordinate_;
	static double kWheelCenterX_;
	static double kWheelCenterY_;
	static double kWheelRadius_;
	static double kWheelAngVelocity_;
	static double kPlatformLength_;
	static double kPlatformWidth_;
	static size_t kNumOfPlatforms_;
	static size_t kNumOfPlayers_;
	static size_t kBackgroundDepth_;
	static size_t kPlatformDepth_;

 public:
	Parameters() {
		std::ifstream in("parameters.txt");
		std::string fake;
		in >> fake >> fake >> kMaxCoordinate_;
		in >> fake >> fake >> kWheelCenterX_;
		in >> fake >> fake >> kWheelCenterY_;
		in >> fake >> fake >> kWheelRadius_;
		in >> fake >> fake >> kWheelAngVelocity_;
		in >> fake >> fake >> kPlatformLength_;
		in >> fake >> fake >> kPlatformWidth_;
		in >> fake >> fake >> kNumOfPlatforms_;
		in >> fake >> fake >> kNumOfPlayers_;
		in >> fake >> fake >> kBackgroundDepth_;
		in >> fake >> fake >> kPlatformDepth_;
		in.close();
	}

	static double kMaxCoordinate()   { return kMaxCoordinate_; }
	static double kWheelCenterX()    { return kWheelCenterX_; }
	static double kWheelCenterY()    { return kWheelCenterY_; }
	static double kWheelRadius()     { return kWheelRadius_; }
	static double kWheelAngVelocity(){ return kWheelAngVelocity_; }
	static double kPlatformLength()  { return kPlatformLength_; }
	static double kPlatformWidth()   { return kPlatformWidth_; }
	static size_t kNumOfPlatforms()  { return kNumOfPlatforms_; }
	static size_t kNumOfPlayers()    { return kNumOfPlayers_; }
	static size_t kBackgroundDepth() { return kBackgroundDepth_; }
	static size_t kPlatformDepth()   { return kPlatformDepth_; }
};


double Parameters::kMaxCoordinate_;
double Parameters::kWheelCenterX_;
double Parameters::kWheelCenterY_;
double Parameters::kWheelRadius_;
double Parameters::kWheelAngVelocity_;
double Parameters::kPlatformLength_;
double Parameters::kPlatformWidth_;
size_t Parameters::kNumOfPlatforms_;
size_t Parameters::kNumOfPlayers_;
size_t Parameters::kBackgroundDepth_;
size_t Parameters::kPlatformDepth_;

class ParametersInitializer {
	static Parameters parameters_;
};

Parameters ParametersInitializer::parameters_;

enum PressedKey {  
	upPlayer1 = 0,
	leftPlayer1 = 1,
	rightPlayer1 = 2,
	upPlayer2 = 3,
	leftPlayer2 = 4,
	rightPlayer2 = 5,
};

#endif
