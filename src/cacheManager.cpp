#include"cacheManager.hpp"
#include"miniCacheManager.hpp"
#include<filesystem>
#include<map>


CacheManager::CacheManager(std::string const& workPlace) {
	if (!std::filesystem::is_directory(workPlace)) {
		std::filesystem::create_directory(workPlace);
	}

	std::array<std::string, 7> dirs = {"/mat_add", "/mat_mult", "/img_rot",
					"/img_gs", "/hs_crc32", "/cche_clr", "/cche_srch"};
	for (size_t i = 0; i < m_cms.size(); ++i) {
		m_cms[i] = MiniCacheManager(workPlace + dirs[i]);
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
