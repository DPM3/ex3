#pragma once

#include"operatorID.hpp"
#include"miniCacheManager.hpp"
#include<array>

class CacheManager {
	std::array<MiniCacheManager,7> m_cms;
	std::string workPlace;
	using miniCacheType = OperatorID::OpType;

	void initCMs();
public:
	CacheManager() = default;
	CacheManager(std::string const& workPlace);
	void runOp(OperatorID op);
	bool isOpIn(OperatorID op);
};
