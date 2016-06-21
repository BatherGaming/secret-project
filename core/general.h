#ifndef __GENERAL_H__
#define __GENERAL_H__

#include <bits/stdc++.h>

class Game;
class Background;
class Platform;
class Player;


const double kPI = atan2(0., -1.);
const std::string kObjectTexturePathsFile = "gui/textures.txt";
 
class Parameters {
 private:
 	static std::map<std::string, double> doubleParameters;
 	static std::map<std::string, size_t> integerParameters;


 public:
	Parameters();
	static double GetDbl(std::string parameter_name);
	static size_t GetInt(std::string parameter_name);
};

class ParametersInitializer {
	static Parameters parameters_;
};

enum Direction{
	left = 0,
	right
};

enum PressedKey {  
	upPlayer1 = 0,
	leftPlayer1,
	rightPlayer1,
	shootPlayer1, 
	upPlayer2,
	leftPlayer2,
	rightPlayer2,
	shootPlayer2,
};

const double epsilon = 1e-9;


#endif
