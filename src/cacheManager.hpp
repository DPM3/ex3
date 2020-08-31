#pragma once

#include"operatorID.hpp"
#include"miniCacheManager.hpp"
#include<array>

class CacheManager {
	std::array<MiniCacheManager,5> m_cms;
	std::string workPlace;
	using miniCacheType = OperatorID::OpType;

	/**
	 * @brief initializes cache managers mini cache managers
	 */
	void initCMs();
public:
	/**
	 * @brief default constructor
	 */
	CacheManager() = default;

	/**
     * @brief real constructor
     *
     * @param[in] workPlace. path to workplace
     */
	CacheManager(std::string const& workPlace);

	/**
     * @brief runs an opperation (command)
     *
     * @param[in] op. Operator id containing all the information about the operation
     */
	void runOp(OperatorID op);
};
