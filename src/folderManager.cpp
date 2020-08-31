#include"folderManager.hpp"

#include<string>
#include<fstream>
#include<filesystem>
#include<exception>

class FolderManager::Marker {
	int m_index;
public:
	Marker& operator++() {
		++m_index;
		m_index -= m_index >= s_maxSize ? s_maxSize : 0;
		return *this;
	}
	Marker operator++(int) {
		Marker result = *this;
		++(*this);
		return result;
	}

	Marker& operator--() {
		--m_index;
		m_index += m_index < 0 ? s_maxSize : 0;
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

	int& index() {
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
	remove(m_files[++m_marker]);
	m_files[m_marker] = fileName;
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
void FolderManager::clear() {
	for (auto& fname : m_files) {
		remove(fname);
		fname = "";
	}
	m_marker.index() = 0;
}

void FolderManager::remove(std::string const& fileName) {
	std::filesystem::remove(m_folderPath + fileName);
}
