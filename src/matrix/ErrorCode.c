#include"ErrorCode.h"
#include<stddef.h>

bool error_isSuccess(ErrorCode code) {
	return code == ERROR_SUCCESS;
}

const char* error_getErrorMessage(ErrorCode code) {
	switch (code) {
		case ERROR_SUCCESS: return "ERROR_SUCCESS";
		case ERROR_ALLOCATING_MEMORY: return "ERROR_ALLOCATING_MEMORY";
		case ERROR_PARAMETER_IS_NULL: return "ERROR_PARAMETER_IS_NULL";
		case ERROR_INDEX_OUT_OF_BOUNDARY: return "ERROR_INDEX_OUT_OF_BOUNDARY";
		case ERROR_MATRIXES_IN_DIFFERENT_SIZE: return "ERROR_MATRIXES_IN_DIFFERENT_SIZE";
		case ERROR_MATRIXES_CANT_BE_MULTIPLIED: return "ERROR_MATRIXES_CANT_BE_MULTIPLIED";
		case ERROR_MATRIX_IS_NOT_INTALIZED_WELL: return "ERROR_MATRIX_IS_NOT_INTALIZED_WELL";
		case ERROR_MATRIX_SIZE_EQUALS_ZERO: return "ERROR_MATRIX_SIZE_EQUALS_ZERO";
		//should never happen:
		default: return NULL;
	}
}
