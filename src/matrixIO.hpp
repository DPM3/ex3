#pragma once
#include<string>
#include"matrix/MatrixClass.hpp"

/**
 * @brief writes matrix to file
 *
 * @param[in] mat. the matrix
 * @param[in] path. the path to the file
 */
void matWrite(MatrixClass mat, std::string const& path);

/**
 * @brief reads matrix from file
 *
 * @param[in] path. path to matrix file
 * @return MatrixClass
 */
MatrixClass matRead(std::string const& path);
