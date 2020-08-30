#include"calculator.hpp"
#include<string>
#include"matrixIO.hpp"
#include"bmp_img/bmp_tester.hpp"


void matAdd(std::string const& lhs, std::string const& rhs, std::string const& out) {
	matWrite(matRead(lhs) + matRead(rhs), out);
}
void matMult(std::string const& lhs, std::string const& rhs, std::string const& out) {
	matWrite(matRead(lhs) * matRead(rhs), out);
}
void imgRot(std::string const& in, std::string const& out) {
	testing::bmp::rotate_image(in, out);
}
void imgGS(std::string const& in, std::string const& out) {
	testing::bmp::convert_to_grayscale(in, out);
}
void hsCrc32(std::string const& in, std::string const& out);
