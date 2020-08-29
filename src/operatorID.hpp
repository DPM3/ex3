struct OperatorID {
	enum class OpType{
		MAT_ADD,
		MAT_MULT,
		IMG_ROT,
		IMG_GS,
		HS_CRC32,
		CCHE_SRCH,
		CCHE_CLR
	} type;

	std::vector<std::string> operands;
	std::string output;
};
