///////////////////////////////////////////////////////////
//  FormatStrategy.h
//  Implementation of the Class FormatStrategy
//  Created on:      02-avr.-2022 14:16:26
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_911417A0_CF45_4639_8C61_9DC8E7AE7373__INCLUDED_)
#define EA_911417A0_CF45_4639_8C61_9DC8E7AE7373__INCLUDED_

#include <string>

class FormatStrategy
{

public:
	FormatStrategy(std::string id);
	virtual ~FormatStrategy() = default;

	virtual std::string format(int time) const =0;

protected:
	struct time_decomposition
	{
		int days;
		int hours;
		int minutes;
		int seconds;
	};

	time_decomposition decomposeTime(int time) const;
	void registerFormatStrategy(std::string id, const FormatStrategy* strategy);
};
#endif // !defined(EA_911417A0_CF45_4639_8C61_9DC8E7AE7373__INCLUDED_)
