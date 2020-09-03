#pragma once
#include<string>
#include<vector>

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

/**
 * @brief returns an operator's hash code value
 *
 * @param[in] op. operator's info
 * @return string
 */
std::string hash(OperatorID op);
