#pragma once

#include<string>
#include<vector>

class FolderManager {
public:
	static constexpr int s_maxSize = 69; //NICE
private:
	std::string m_folderPath;
	std::string m_files[s_maxSize];

	class Marker {
		int m_index;
	public:
		Marker& operator++();
		Marker operator++(int);
		Marker& operator--();
		Marker operator--(int);
		operator int();
		int& index();
	};
	Marker m_marker;

public:

	FolderManager() = default;
	FolderManager(std::string const& pathToDir);

	void add(std::string const& fileName, std::string const& fileSource); //takes care of removing from cache last file
	bool fileExists(std::string const& fileName);
	void clear();
	void save();
	std::string folderPath();
private:
	void remove(std::string const& fileName);
};
