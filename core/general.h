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
 	std::map<string, double> dbl;
 	std::map<string, size_t> integer;


 public:
	Parameters() {
		std::ifstream in ("core/parameters.txt");
		std::string fake;
		while(!in.eof()){
			in >> fake >> fake >> kMaxCoordinate_;
		}
		in.close();
	}

};

class ParametersInitializer {
	static Parameters parameters_;
};

enum PressedKey {  
	upPlayer1 = 0,
	leftPlayer1 = 1,
	rightPlayer1 = 2,
	upPlayer2 = 3,
	leftPlayer2 = 4,
	rightPlayer2 = 5,
};



#endif
