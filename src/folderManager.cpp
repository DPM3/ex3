#include"folderManager.hpp"
#include<fstream>

FolderManager::FolderManager(std::string const& pathToDir)
	: m_folderPath{pathToDir}, m_files(s_maxSize) { }

FolderManager::FolderManager(std::string const& stateFilePath) {
	ifstream stateFile{stateFilePath};
}

void FolderManager::add(std::string const& fileName); //takes care of removing from cache
bool FolderManager::fileExists(std::string const& fileName);
void FolderManager::clear();
void FolderManager::remove(std::string const& fileName);
