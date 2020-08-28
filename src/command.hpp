#pragma once

#include<string>

struct Command {
	virtual void exec(std::string const& command) = 0;
};
