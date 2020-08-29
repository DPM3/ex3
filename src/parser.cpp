#include"parser.hpp"
#include<cstring>

OperatorID parser::parseCommand(std::vector<std::string> const& cmd) {
	switch(cmd[0]) {
		case "matrix":
			switch(cmd[1]) {
				case "add":
					return OperatorID{
				case "multiply":
			}
		case "image":
			switch(cmd[1]) {
				case "rotate":
				case "convert":
			}
		case "hash":
			switch(cmd[1]) {
				case "crc32":
			}
		case "cache":
			switch(cmd[1]) {
				case "clear":
				case "search":
			}
	}
}
