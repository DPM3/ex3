#include<string>
#include"folderManager.hpp"
#include"operatorID.hpp"

class MiniCacheManager {
	FolderManager folderManager;
public:
	MiniCacheManager(std::string const& workPlace);
	bool isInCache(OperatorID const& id);
	void addOperation(OperatorID const& id, std::string const& resultPath);
};
