#include<string>
#include"folderManager.hpp"
#include"operatorID.hpp"

class MiniCacheManager {
	FolderManager folderManager;
public:
	MiniCacheManager(std::string const& workPlace);
	template<typename OpID>
		bool isInCache(OpID const& id);
	template<typename OpID>
		void addOperation(OpID const& id, std::string const& resultPath);
};
