#include<iostream>
#include<vector>
#include"cacheManager.hpp"
#include"parser.hpp"
#include"operatorID.hpp"

int main(int argc, char** argv) {
	CacheManager cm ("./cache");
	std::vector<std::string> args;
	for (auto i = 0; i < argc; ++i) {
		args.emplace_back( std::string(argv[i]) );
	}
	OperatorID op = parseCommand(args);
	cm.runOp(op);
}
