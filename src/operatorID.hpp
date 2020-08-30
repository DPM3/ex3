#include<string>
#include<vector>
#include"sha1.hpp"
struct OperatorID {
	enum OpType{
		MAT_ADD,
		MAT_MULT,
		IMG_ROT,
		IMG_GS,
		HS_CRC32,
		CCHE_CLR,
		CCHE_SRCH
	} type;

	std::vector<std::string> operands;
	std::string output;
};

std::string hash(OperatorID op);
