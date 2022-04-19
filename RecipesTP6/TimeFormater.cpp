///////////////////////////////////////////////////////////
//  TimeFormater.cpp
//  Implementation of the Class TimeFormater
//  Created on:      02-avr.-2022 14:16:26
//  Original author: francois
///////////////////////////////////////////////////////////

#include <stdexcept>

#include "TimeFormater.h"


TimeFormater::TimeFormater()
	: m_FormatStrategy(nullptr)
{
}

void TimeFormater::registerFormatStrategy(std::string id, const FormatStrategy* strategy)
{
	m_strategyRegistry[id] = strategy;
}

TimeFormater& TimeFormater::getInstance()
{
	static TimeFormater instance;
	return instance;
}

std::string TimeFormater::formatTime(int time)
{
	std::string sReturn = (getInstance().m_FormatStrategy != nullptr) ? getInstance().m_FormatStrategy->format(time) : std::to_string(time);
	return  sReturn;
}

void TimeFormater::selectFormatStrategy(std::string strategy_id)
{
	const FormatStrategy* newStrategy = getInstance().m_strategyRegistry[strategy_id];
	if (newStrategy != nullptr)
		getInstance().m_FormatStrategy = newStrategy;
	else
	{
		std::string strategy_not_found("Time format strategy not found: ");
		strategy_not_found += strategy_id;
		throw(std::domain_error(strategy_not_found));
	}
}
