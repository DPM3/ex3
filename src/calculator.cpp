#include"calculator.hpp"
#include<string>

//NOTE: THIS FILE IS VERY MUCH NOT FOR USE!!!!!!!!!
//DO NOT USE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//WARNING: IF YOU USE THIS YOU WILL GET SHOT AND STABBED AND RUNOVER; YOU WILL DIE!!!!!!
//OSI MODEL DA DA DA DA DA DA

namespace {
	void matWrite(std::string const& path); //THIS IS NOT USEABLE YET!!!!!
	void matRead(std::string const& path);  //THIS IS NOT USEABLE YET!!!!!
}
void matAdd(std::string const& lhs, std::string const& rhs, std::string const& out) {
	matWrite(matRead(lhs) + matRead(rhs), out);
}
void matMult(std::string const& lhs, std::string const& rhs, std::string const& out) {
	matWrite(matRead(lhs) * matRead(rhs), out);
}
void imgRot(std::string const& in, std::string const& out);
void imgGS(std::string const& in, std::string const& out);
void hsCrc32(std::string const& in, std::string const& out);
