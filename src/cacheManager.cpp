#include"cacheManager.hpp"
#include<filesystem>
#include"miniCacheManager.hpp"
#include"calculator.hpp"


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
		std::filesystem::copy_file(m_cms[op.type].getFileName(op), op.output);
	} else {
		switch(op.type) {
			case OperatorID::MAT_ADD:
				calc::matAdd(op.operands[0], op.operands[1], op.output);
				break;
			case OperatorID::MAT_MULT: break;
			case OperatorID::IMG_ROT: break;
			case OperatorID::IMG_GS: break;
			case OperatorID::HS_CRC32: break;
			case OperatorID::CCHE_CLR: break;
			case OperatorID::CCHE_SRCH: break;
		}
	}
}
bool CacheManager::isOpIn(OperatorID op) {
	return m_cms[op.type].isInCache(op);
}
