#pragma once

#include"operatorID.hpp"
#include"miniCacheManager.hpp"

class CacheManager {
	MiniCacheManager m_cms[7];
	using miniCacheType = OperatorID::OpType;
public:
	CacheManager() = default;
	CacheManager(std::string const& workPlace);
	void runOp(OperatorID op);
	bool isOpIn(OperatorID op);
};
