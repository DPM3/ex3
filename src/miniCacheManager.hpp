#pragma once
#include<string>
#include"folderManager.hpp"
#include"operatorID.hpp"

class MiniCacheManager {
	FolderManager m_folderManager;
public:
	/**
     * @brief default constructor
     */
	MiniCacheManager() = default;

	/**
     * @brief real constructor
     *
     * @param[in] workPlace. path to work place
     */
	MiniCacheManager(std::string const& workPlace);

	/**
     * @brief checks if operation is in mini cache
     *
     * @param[in] id. operator's info
     * @return boolean
     */
	bool isInCache(OperatorID const& id);

	/**
     * @brief adds operation to mini cache
     *
     * @param[in] id. operation's info.
     * @param[in] resultPath. path to operation's result
     */
	void addOp(OperatorID const& id, std::string const& resultPath);

	/**
     * @brief returns file's name
     *
     * @param[in] id. operation's info
     * @return string
     */
	std::string getFileName(OperatorID const& id);

	/**
     * @brief returns mini cache's work place
     *
     * @return string 
     */
	std::string workPlace();
	void save();
};
