#include<iostream>
#include<vector>
#include<exception>
#include"cacheManager.hpp"
#include"parser.hpp"
#include"operatorID.hpp"
#include"matrix/ErrorCodeException.hpp"

int main(int argc, char** argv) {
	try {
		CacheManager cm ("./cache");
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
