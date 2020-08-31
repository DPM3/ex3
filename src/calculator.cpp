#include"calculator.hpp"
#include<string>
#include<fstream>
#include"matrixIO.hpp"
#include"bmp_img/bmp_tester.hpp"
/*
extern "C" {
#include"crc32.c"
}
*/
#include"crc32.hpp"


void calc::matAdd(std::string const& lhs, std::string const& rhs, std::string const& out) {
	matWrite(matRead(lhs) + matRead(rhs), out);
}

void calc::matMult(std::string const& lhs, std::string const& rhs, std::string const& out) {
	matWrite(matRead(lhs) * matRead(rhs), out);
}

void calc::hsCRC32(std::string const& in, std::string const& out) {
	std::ifstream infs (in);
	if (!infs) {
		throw std::runtime_error("Could not access file for reading: " + in);
	}
	std::ofstream outfs (out);
	if (!outfs) {
		throw std::runtime_error("Could not access file for writing: " + out);
	}

	std::string inContent;
	infs >> inContent;

	uint32_t table[256];
	crc32::generate_table(table);
	uint32_t crc = crc32::update(table, 0, inContent.c_str(), inContent.size());
	outfs << std::to_string(crc);
	outfs.close();
	infs.close();
}

void calc::imgRot(std::string const& in, std::string const& out) {
	testing::bmp::rotate_image(in, out);
}

void calc::imgGS(std::string const& in, std::string const& out) {
	testing::bmp::convert_to_grayscale(in, out);
}
