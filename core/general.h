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
	Parameters() {
		std::ifstream in ("core/parameters.txt");
		std::string fake;
		while(!in.eof()){
			std::string parameterName;	
			in >> parameterName;
			if(parameterName[0]=='#') break;
			in >> fake >> doubleParameters[parameterName];
		}
		while(!in.eof()){
			std::string parameterName;	
			in >> parameterName;
			in >> fake >> integerParameters[parameterName];
		}
		in.close();
	}
	static double GetDbl(std::string parameter_name){
		return doubleParameters[parameter_name];
	}
	static size_t GetInt(std::string parameter_name){
		return integerParameters[parameter_name];
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
