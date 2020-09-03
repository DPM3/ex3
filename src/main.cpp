#include<iostream>
#include<vector>
#include<exception>
#include<string>
#include<cstring>
#include"cacheManager.hpp"
#include"parser.hpp"
#include"operatorID.hpp"
#include"matrix/ErrorCodeException.hpp"

int main(int argc, char** argv) {
	//first get the path to executable, to put cache folder there
	std::string pathToExec;
	for (size_t i = 0; i < std::strlen(argv[0]) - std::strlen("ex3.out"); ++i) {
		pathToExec += argv[0][i];
	}

	try {
		CacheManager cm (pathToExec + "cache");
		std::vector<std::string> args;
		for (auto i = 1; i < argc; ++i) {
			args.emplace_back( std::string(argv[i]) );
		}
		OperatorID op = parseCommand(args);
		cm.runOp(op);
		cm.save();
	} catch (std::exception& e) {
		std::cout << "ERROR -- EXCEPTION THROWN:" << std::endl << e.what() << std::endl;
	} catch (ErrorCodeException& e) {
		std::cout << "ERROR -- EXCEPTION THROWN:" << std::endl;
		e.printErrorMessage();
	}
}
