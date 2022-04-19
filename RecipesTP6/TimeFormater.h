///////////////////////////////////////////////////////////
//  TimeFormater.h
//  Implementation of the Class TimeFormater
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_55FD3DA8_7F88_487a_B6BA_B343D05271BA__INCLUDED_)
#define EA_55FD3DA8_7F88_487a_B6BA_B343D05271BA__INCLUDED_

#include <string>
#include <memory>
#include <map>

#include "FormatStrategy.h"

class TimeFormater
{
public:
	static std::string formatTime(int time);
	static void selectFormatStrategy(std::string strategy_id);

private:
	friend class FormatStrategy;

	TimeFormater();
	virtual ~TimeFormater() = default;

	void registerFormatStrategy(std::string id, const FormatStrategy* strategy);

	static TimeFormater& getInstance();

	std::map<std::string, const FormatStrategy*> m_strategyRegistry;
	const FormatStrategy* m_FormatStrategy;
};
#endif // !defined(EA_55FD3DA8_7F88_487a_B6BA_B343D05271BA__INCLUDED_)
