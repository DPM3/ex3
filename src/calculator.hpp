#pragma once
#include<string>

namespace calc {
/**
 * @brief calculates the sum of 2 matrices
 *
 * @param[in] lhs. left matrix
 * @param[in] rhs. right matrix
 * @param[out] out. result matrix
 */
void matAdd(std::string const& lhs, std::string const& rhs, std::string const& out);

/**
 * @brief calculates the product of 2 matrices
 *
 * @param[in] lhs. left matrix
 * @param[in] rhs. right matrix
 * @param[out] out. result matrix
 */
void matMult(std::string const& lhs, std::string const& rhs, std::string const& out);

/**
 * @brief calculates rotation of image
 *
 * @param[in] in. original image
 * @param[out] out. rotated image
 */
void imgRot(std::string const& in, std::string const& out);

/**
 * @brief calculates gray scale image
 *
 * @param[in] in. original image
 * @param[out] out. gray scale image
 */
void imgGS(std::string const& in, std::string const& out);

/**
 * @brief calculates string's hash value
 *
 * @param[in] in. the string
 * @param[out] out. the string's hash value
 */
void hsCRC32(std::string const& in, std::string const& out);
}
