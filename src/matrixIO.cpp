#include"matrixIO.hpp"
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<streambuf>
#include"matrix/MatrixClass.hpp"

void matWrite(MatrixClass mat, std::string const& path) {
	std::ofstream ofs (path);
	if (!ofs) {
		throw std::runtime_error("could not open file for writing: " + path);
	}
	for (uint32_t i = 0; i < mat.getHeight(); ++i) {
	for (uint32_t j = 0; j < mat.getWidth(); ++j) {
		ofs << std::to_string(mat(i,j));
		if (j != mat.getWidth() - 1) {
			ofs << ",";
		} else {
			ofs << "\n";
		}
	}
	}
}
MatrixClass matRead(std::string const& path) {
	std::ifstream ifs (path);
	if (!ifs) {
		throw std::runtime_error("could not open file for reading: " + path);
	}

	std::string content ((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

	int width, height = 0;
	int numOfElems = 0;
	std::string num;
	std::vector<double> nums;


	for (char c : content) {
		switch (c) {
			case ' ':
			case '\t':
				break;
			case ',':
				nums.push_back(std::stod(num));
				num = "";
				++numOfElems;
				break;
			case '\n':
				nums.push_back(std::stod(num));
				num = "";
				++height;
				++numOfElems;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '.':
			case '-':
				num += c;
				break;
			default:
				throw std::runtime_error("bad matrix file");
		}
	}

	//now height and width are correct
	width = numOfElems / height;

	MatrixClass mat (height, width);
	for (uint32_t i = 0; i < mat.getHeight(); ++i) {
	for (uint32_t j = 0; j < mat.getWidth() ; ++j) {
		mat.setValue(i, j, nums[i * mat.getWidth() + j]);
	}
	}
	return mat;
}
