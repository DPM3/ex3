#pragma once
#include<string>
#include<vector>

struct OperatorID {
	enum OpType{ //Yes, this is an enum, and not enum class on perpose. You can't do: arr[MAT_ADD] with enum class.
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
