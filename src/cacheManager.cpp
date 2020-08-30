#include"cacheManager.hpp"
#include<filesystem>
#include<fstream>
#include<iostream>
#include"miniCacheManager.hpp"
#include"calculator.hpp"
#include"parser.hpp"

void CacheManager::initCMs() {
	std::array<std::string, 5> dirs = {"/mat_add", "/mat_mult", "/img_rot",
					"/img_gs", "/hs_crc32"};
	for (size_t i = 0; i < m_cms.size(); ++i) {
		m_cms[i] = MiniCacheManager(workPlace + dirs[i]);
	}
}
CacheManager::CacheManager(std::string const& workPlace) : workPlace{workPlace} {
	if (!std::filesystem::is_directory(workPlace)) {
		std::filesystem::create_directory(workPlace);
	}

	initCMs();
}

void CacheManager::runOp(OperatorID op) {
	if (m_cms[op.type].isInCache(op)) {
		std::filesystem::copy_file(m_cms[op.type].getFileName(op), op.output);
	} else {
		switch(op.type) {
			case OperatorID::MAT_ADD:
				calc::matAdd(op.operands[0], op.operands[1], op.output);
				m_cms[op.type].addOp(op, op.output);
				break;
			case OperatorID::MAT_MULT:
				calc::matMult(op.operands[0], op.operands[1], op.output);
				m_cms[op.type].addOp(op, op.output);
				break;
			case OperatorID::IMG_ROT:
				calc::imgRot(op.operands[0],op.output);
				m_cms[op.type].addOp(op, op.output);
				break;
			case OperatorID::IMG_GS:
				calc::imgGS(op.operands[0], op.output);
				m_cms[op.type].addOp(op, op.output);
				break;
			case OperatorID::HS_CRC32:
				calc::hsCRC32(op.operands[0], op.output);
				m_cms[op.type].addOp(op, op.output);
				break;
			case OperatorID::CCHE_CLR:
				for (auto cm : m_cms) {
					std::filesystem::remove_all(cm.workPlace());
				}
				initCMs();
				break;
			case OperatorID::CCHE_SRCH:
				OperatorID actualOp = parseCommand(op.operands);
				if (m_cms[actualOp.type].isInCache(actualOp)) {
					std::cout << "Found In Cache" << std::endl;
				} else {
					std::cout << "NOT Found In Cache" << std::endl;
				}
				break;
		}
	}
}
