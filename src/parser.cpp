#include"parser.hpp"
#include<cstring>
#include<algorithm>

OperatorID parser::parseCommand(std::vector<std::string> const& cmd) {
	switch(cmd[0]) {
		case "matrix":
			switch(cmd[1]) {
				case "add":
					return OperatorID{MAT_ADD, {cmd[2], cmd[3]}, cmd[4]};
				case "multiply":
					return OperatorID{MAT_MULT, {cmd[2], cmd[3]}, cmd[4]};
			}
		case "image":
			switch(cmd[1]) {
				case "rotate":
					return OperatorID{IMG_ROT, {cmd[2]}, cmd[3]};
				case "convert":
					return OperatorID{IMG_GS, {cmd[2]}, cmd[3]};
			}
		case "hash":
			switch(cmd[1]) {
				case "crc32":
					return OperatorID{HS_CRC32, {cmd[2]}, cmd[3]};
			}
		case "cache":
			switch(cmd[1]) {
				case "clear":
					return OperatorID{CCHE_CLR, {}, ""};
				case "search":
					std::vector<std::string> operands;
					std::for_each(cmd.begin() + 2, cmd.end(), [&operands](std::string const& str) {
						operands.emplace_back(str);
					});
					return OperatorID{CCHE_SRCH, operands, ""};
			}
	}
}
