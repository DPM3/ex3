#include"folderManager.hpp"

#include<string>
#include<fstream>
#include<filesystem>
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

FolderManager::FolderManager(std::string const& stateFilePath) : m_marker{0} {
	std::ifstream stateFile{stateFilePath + "/STATE"};
	if (!stateFile) {
		throw std::runtime_error{"Coudn't open file: " + stateFilePath};
	}

	for (std::string line; std::getline(stateFile, line); ) {
		m_files[m_marker++] = line;
	}
}


void FolderManager::add(std::string const& fileName, std::string const& fileSource) {
	m_files[m_marker++] = fileName;
	std::filesystem::copy_file(fileSource, m_folderPath + fileName);
}

bool FolderManager::fileExists(std::string const& fileName) {
	for (auto fname : m_files) {
		if (fname == fileName) {
			return true;
		}
	}
	return false;
}
void FolderManager::clear() { }
void FolderManager::remove(std::string const& fileName) { }
