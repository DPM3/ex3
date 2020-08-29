#include"folderManager.hpp"

#include<string>
#include<fstream>
#include<exception>

struct FolderManager::Marker {
	int m_index;
	Marker& operator++() {
		(++m_index) %= FolderManager::s_maxSize;
		return *this;
	}
	Marker operator++(int) {
		Marker result = *this;
		++(*this);
		return result;
	}

	Marker& operator--() {
		(--m_index) %= FolderManager::s_maxSize;
		return *this;
	}
	Marker operator--(int) {
		Marker result = *this;
		--(*this);
		return result;
	}

	operator int() {
		return m_index;
	}
};

FolderManager::FolderManager(std::string const& stateFilePath) {
	std::ifstream stateFile{stateFilePath};
	if (!stateFile) {
		throw std::runtime_error{"Coudn't open file: " + stateFilePath};
	}

	//TODO
}


void FolderManager::add(std::string const& fileName) {
	m_files[m_marker++] = fileName;
}

bool FolderManager::fileExists(std::string const& fileName) { return false; }
void FolderManager::clear() { }
void FolderManager::remove(std::string const& fileName) { }
