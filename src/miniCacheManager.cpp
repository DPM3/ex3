#include"miniCacheManager.hpp"
#include<string>
#include<operatorID.hpp>

MiniCacheManager::MiniCacheManager(std::string const& workPlace) : folderManager(workPlace) { }

bool MiniCacheManager::isInCache(OperatorID const& id) {
	return folderManager.fileExists(hash(id));
}
void MiniCacheManager::addOp(OperatorID const& id, std::string const& resultPath) {
	folderManager.add(hash(id), resultPath);
}
std::string MiniCacheManager::getFileName(OperatorID const& id) {
	return workPlace() + hash(id);
}
std::string MiniCacheManager::workPlace() {
	return folderManager.folderPath();
}
