#pragma once

#include"operatorID.hpp"

/**
 * @brief returns a commands operator's info
 *
 * @param[in] cmd. the args from the command line
 * @return OperatorID
 */
OperatorID parseCommand(std::vector<std::string> const& cmd);
