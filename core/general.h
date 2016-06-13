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
const std::string kObjectTexturePathsFile = "gui/textures.txt";
 
class Parameters {
 private:
	static double kMaxCoordinate_;
	static double kWheelCenterX_;
	static double kWheelCenterY_;
	static double kWheelRadius_;
	static double kWheelAngVelocity_;
	static double kPlatformLength_;
	static double kPlatformWidth_;
	static double kPlayerLength_;
	static size_t kNumOfPlatforms_;
	static size_t kNumOfPlayers_;
	static size_t kBackgroundDepth_;
	static size_t kPlatformDepth_;
	static size_t kPlayerDepth_;
	static size_t kWindowWidth_;
	static size_t kWindowHeight_;


 public:
	Parameters() {
		std::ifstream in ("core/parameters.txt");
		std::string fake;
		in >> fake >> fake >> kMaxCoordinate_;
		in >> fake >> fake >> kWheelCenterX_;
		in >> fake >> fake >> kWheelCenterY_;
		in >> fake >> fake >> kWheelRadius_;
		in >> fake >> fake >> kWheelAngVelocity_;
		in >> fake >> fake >> kPlatformLength_;
		in >> fake >> fake >> kPlatformWidth_;
		in >> fake >> fake >> kPlayerLength_;
		in >> fake >> fake >> kNumOfPlatforms_;
		in >> fake >> fake >> kNumOfPlayers_;
		in >> fake >> fake >> kBackgroundDepth_;
		in >> fake >> fake >> kPlatformDepth_;
		in >> fake >> fake >> kPlayerDepth_;
		in >> fake >> fake >> kWindowWidth_;
		in >> fake >> fake >> kWindowHeight_;
		in.close();
	}

	static double kMaxCoordinate()   { return kMaxCoordinate_; }
	static double kWheelCenterX()    { return kWheelCenterX_; }
	static double kWheelCenterY()    { return kWheelCenterY_; }
	static double kWheelRadius()     { return kWheelRadius_; }
	static double kWheelAngVelocity(){ return kWheelAngVelocity_; }
	static double kPlatformLength()  { return kPlatformLength_; }
	static double kPlatformWidth()   { return kPlatformWidth_; }
	static double kPlayerLength()    { return kPlayerLength_; }
	static size_t kNumOfPlatforms()  { return kNumOfPlatforms_; }
	static size_t kNumOfPlayers()    { return kNumOfPlayers_; }
	static size_t kBackgroundDepth() { return kBackgroundDepth_; }
	static size_t kPlatformDepth()   { return kPlatformDepth_; }
	static size_t kPlayerDepth()     { return kPlayerDepth_;}
	static size_t kWindowWidth()     { return kWindowWidth_; }
	static size_t kWindowHeight()    { return kWindowHeight_; }
};

class ParametersInitializer {
	static Parameters parameters_;
};

enum PressedKey {  
	upPlayer1 = 0,
	leftPlayer1,
	rightPlayer1,
	downPlayer1, 
	upPlayer2,
	leftPlayer2,
	rightPlayer2,
	downPlayer2
};



#endif
