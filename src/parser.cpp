#include"parser.hpp"
#include<cstring>
#include<algorithm>
#include<stdexcept>
#include<iostream>
#include"operatorID.hpp"

OperatorID parseCommand(std::vector<std::string> const& cmd) {
	for (auto word : cmd) {
		std::cout << word;
	}
	//using if-else because switch statements only work for integers... oof
	if (cmd[0] == "matrix") {
		if (cmd[1] == "add") {
			return OperatorID{OperatorID::MAT_ADD, {cmd[2], cmd[3]}, cmd[4]};
		} else if (cmd[1] == "multiply") {
			return OperatorID{OperatorID::MAT_MULT, {cmd[2], cmd[3]}, cmd[4]};
		}
	} else if (cmd[0] == "image") {
		if (cmd[1] == "rotate") {
			return OperatorID{OperatorID::IMG_ROT, {cmd[2]}, cmd[3]};
		} else if (cmd[1] == "convert") {
			return OperatorID{OperatorID::IMG_GS, {cmd[2]}, cmd[3]};
		}
	} else if (cmd[0] == "hash") {
		if (cmd[1] == "crc32") {
			return OperatorID{OperatorID::HS_CRC32, {cmd[2]}, cmd[3]};
		}
	} else if (cmd[0] == "cache") {
		if (cmd[1] == "clear") {
			return OperatorID{OperatorID::CCHE_CLR, {}, ""};
		} else if (cmd[1] == "search") {
			std::vector<std::string> operands;
			std::for_each(cmd.begin() + 2, cmd.end(), [&operands](std::string const& str) {
				operands.emplace_back(str);
			});
			return OperatorID{OperatorID::CCHE_SRCH, operands, ""};
		}
	}
	throw std::runtime_error("Illegal Command");
}
