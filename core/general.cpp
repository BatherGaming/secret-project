#include "general.h"

std::map<std::string, double> Parameters::doubleParameters;
std::map<std::string, size_t> Parameters::integerParameters;
Parameters ParametersInitializer::parameters_;


Parameters::Parameters(){
	std::ifstream in ("core/parameters.txt");
	std::string fake;
	while(!in.eof()){
		std::string parameterName;	
		in >> parameterName;
		if(parameterName[0]=='#') break;
		in >> fake >> doubleParameters[parameterName];
		std::cerr << parameterName << " " << doubleParameters[parameterName] << std::endl;
	}
	while(!in.eof()){
		std::string parameterName;	
		in >> parameterName;
		in >> fake >> integerParameters[parameterName];
		std::cerr << parameterName << " " << integerParameters[parameterName] << std::endl;
	}

	std::cerr << "Done" << std::endl;
	in.close();
}
double Parameters::GetDbl(std::string parameter_name){
		if(!doubleParameters.count(parameter_name)){
			std::cerr << "BAD: " << parameter_name << std::endl;
		}
		return doubleParameters[parameter_name];
	}
size_t Parameters::GetInt(std::string parameter_name){
		if(!integerParameters.count(parameter_name)){
			std::cerr << "BAD: " << parameter_name << std::endl;
		}
		return integerParameters[parameter_name];
	}
