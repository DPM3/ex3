#pragma once

#include<string>
#include<vector>

class FolderManager {
	std::string m_folderPath;
	std::vector<File> m_files;

public:
	static constexpr int s_maxSize = 69; //NICE

	FolderManager(std::string const& pathToDir, int maxSize);
	FolderManager(std::string const& pathToSavedFolder);

	void add(std::string const& fileName); //takes care of removing from cache
	bool fileExists(std::string const& fileName);
	void clear();
	void save(std::string const& path);

private:
	void remove(std::string const& fileName);
};
