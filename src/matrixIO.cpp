#include"matrixIO.hpp"
#include<fstream>
#include<string>
#include"matrix/MatrixClass.hpp"

void matWrite(MatrixClass mat, std::string const& path) {
	ofstream ofs (path);
	if (!ofs) {
		throw runtime_error("could not open file for writing: " + path);
	}
	for (int i = 0; i < mat.getHeight(); ++i) {
	for (int j = 0; j < mat.getWidth(); ++j) {
		ofs << mat(i,j);
		if (j != mat.getWidth() - 1) {
			ofs << ",";
		}
	}
	}
}
MatrixClass matRead(std::string const& path) {
	ifstream ifs (path);
	if (!ifs) {
		throw runtime_error("could not open file for reading: " + path);
	}

	std::string num;
	std::vector<std::string> content;
	int i = 0, j = 0, index = 0;
	for (char c; c != EOF;) {
		ifs.get(c);
		switch (c) {
			case ' ':
			case '\t':
				break;
			case ',':
				++i, ++index;
				content[index] = num;
				num = "";
				break;
			case '\n':
				i = 0;
				++j, ++index;
				num = "";
				break;
			default:
				num += c;
		}
	}

	MatrixClass mat (i + 1, j + 1);
	for (int i = 0; i < mat.getHeight(); ++i) {
	for (int j = 0; j < mat.getWidth(); ++j) {
		mat.setValue(i, j, content[i * mat.getWidth() + j]);
	}
	}

	return mat;
}
