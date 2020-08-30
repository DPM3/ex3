#include"sha1.hpp"

//this file is an implementation of sha1 we found online.
export "C" {
#include"sha1Lib.c"
}

std::string sha1(std::string const& content) {
	char* result;
	sha1digest(NULL, result, content.c_str(), content.size()+1); //I know I'm using NULL, it's because this is a C func
	return std::string {result};
}
