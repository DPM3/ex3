#include"miniCacheManager.hpp"
#include<string>
#include<operatorID.hpp>

MiniCacheManager::MiniCacheManager(std::string const& workPlace) : m_folderManager(workPlace) { }

bool MiniCacheManager::isInCache(OperatorID const& id) {
	if (id.type == OperatorID::CCHE_CLR ||
			id.type == OperatorID::CCHE_SRCH) {

		return false;
	}
	return m_folderManager.fileExists(hash(id));
}
void MiniCacheManager::addOp(OperatorID const& id, std::string const& resultPath) {
	m_folderManager.add(hash(id), resultPath);
}
std::string MiniCacheManager::getFileName(OperatorID const& id) {
	return workPlace() + hash(id);
}
std::string MiniCacheManager::workPlace() {
	return m_folderManager.folderPath();
}

void MiniCacheManager::save() {
	m_folderManager.save();
}
