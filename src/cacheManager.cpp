#include"cacheManager.hpp"
#include"miniCacheManager.hpp"
#include<filesystem>


CacheManager::CacheManager(std::string const& workPlace)
	/*
	: m_cms{
	workPlace + "/mat_add",
	workPlace + "/mat_mult",
	workPlace + "/img_rot",
	workPlace + "/img_gs",
	workPlace + "/hs_crc32",
	workPlace + "/cche_clr",
	workPlace + "/cche_srch"
	}*/ {
	if (!std::filesystem::is_directory(workPlace)) {
		std::filesystem::create_directory(workPlace);
	}
}

void CacheManager::runOp(OperatorID op) {
	if (m_cms[op.type].isInCache(op)) {
		//TODO: copy to op.outPath
	} else {
		//TODO: actually calculate the result
	}
}
bool CacheManager::isOpIn(OperatorID op) {
	return m_cms[op.type].isInCache(op);
}
