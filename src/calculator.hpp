#pragma once
#include<string>

namespace calc {
void matAdd(std::string const& lhs, std::string const& rhs, std::string const& out);
void matMult(std::string const& lhs, std::string const& rhs, std::string const& out);
void imgRot(std::string const& in, std::string const& out);
void imgGS(std::string const& in, std::string const& out);
void hsCRC32(std::string const& in, std::string const& out);
}
