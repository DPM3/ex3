#pragma once

#include"operatorID.hpp"
#include"miniCacheManager.hpp"
#include<array>

class CacheManager {
	std::array<MiniCacheManager,7> m_cms;
	using miniCacheType = OperatorID::OpType;
public:
	CacheManager() = default;
	CacheManager(std::string const& workPlace);
	void runOp(OperatorID op);
	bool isOpIn(OperatorID op);
};
