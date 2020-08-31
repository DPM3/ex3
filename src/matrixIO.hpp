#pragma once
#include<string>
#include"matrix/MatrixClass.hpp"

void matWrite(MatrixClass mat, std::string const& path);
MatrixClass matRead(std::string const& path);
