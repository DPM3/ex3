#include"operatorID.hpp"
#include<string>
#include<fstream>
#include<cstring>
#include"sha1.hpp"
#include"matrixIO.hpp"

std::string hash(OperatorID op) {
	std::ifstream ifs, ifs2;
	std::string content;
	std::string hash, hash2;
	switch (op.type) {
		case OperatorID::MAT_ADD:
			ifs = std::ifstream(op.operands[0]);
			ifs >> content;
			ifs2 = std::ifstream(op.operands[1]);
			ifs2 >> content;
			hash = sha1(content);

			content = "";
			ifs2 >> content;
			ifs >> content;
			hash2 = sha1(content);

			return std::strcmp(hash.c_str(), hash2.c_str()) == 1 ? hash : hash2;

		case OperatorID::MAT_MULT:
			ifs = std::ifstream(op.operands[0]);
			ifs >> content;
			ifs2 = std::ifstream(op.operands[1]);
			ifs2 >> content;
			return sha1(content);

		case OperatorID::IMG_ROT:
		case OperatorID::IMG_GS:
		case OperatorID::HS_CRC32:
			ifs = std::ifstream(op.operands[0]);
			ifs >> content;
			return sha1(content + std::string{ (char)(op.type + 1) } );
			break;

		default: return "kzlx;dgkilshjdfg;";
	}
}
