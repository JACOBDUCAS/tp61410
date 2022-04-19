///////////////////////////////////////////////////////////
//  LitteralFormatStrategy.h
//  Implementation of the Class LitteralFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_324DF7CD_C33B_4c5e_B4A0_3FD258029130__INCLUDED_)
#define EA_324DF7CD_C33B_4c5e_B4A0_3FD258029130__INCLUDED_

#include "FormatStrategy.h"

class LitteralFormatStrategy : public FormatStrategy
{
public:
	virtual std::string format(int time) const;

private:
	LitteralFormatStrategy();
	virtual ~LitteralFormatStrategy() = default;

	static LitteralFormatStrategy instance;
	inline static const std::string LitteralFormat = "litteral";
};
#endif // !defined(EA_324DF7CD_C33B_4c5e_B4A0_3FD258029130__INCLUDED_)
