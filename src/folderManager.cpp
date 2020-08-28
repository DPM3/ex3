#include"folderManager.hpp"

#include<string>
#include<fstream>
#include<exception>

struct FolderManager::Marker {
	int m_index;
	Marker& operator++() {
		(++m_index) %= FolderManager::s_maxSize;
	}
	Marker operator++(int) { ++(*this); }

	Marker& operator--() {
		(--m_index) %= FolderManager::s_maxSize;
	}
	Marker operator--(int) { --(*this); }

	operator int() {
		return m_index;
	}
};

FolderManager::FolderManager(std::string const& pathToDir)
	: m_folderPath{pathToDir}, m_files(s_maxSize) { }

FolderManager::FolderManager(std::string const& stateFilePath) : m_files(s_maxSize) {
	ifstream stateFile{stateFilePath};
	if (!stateFile) {
		throw std::exception{"Coudn't open file: " + stateFilePath};
	}

	//TODO
}


void FolderManager::add(std::string const& fileName) {
	m_files[marker++] = fileName;
}

bool FolderManager::fileExists(std::string const& fileName);
void FolderManager::clear();
void FolderManager::remove(std::string const& fileName);
