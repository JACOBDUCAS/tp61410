///////////////////////////////////////////////////////////
//  NumericFormatStrategy.h
//  Implementation of the Class NumericFormatStrategy
//  Created on:      02-avr.-2022 14:16:26
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_AA77EA40_BD62_4da2_A4B1_24E0543D0FA7__INCLUDED_)
#define EA_AA77EA40_BD62_4da2_A4B1_24E0543D0FA7__INCLUDED_

#include "FormatStrategy.h"

class NumericFormatStrategy : public FormatStrategy
{
public:
	virtual std::string format(int time) const;

private:
	NumericFormatStrategy();
	virtual ~NumericFormatStrategy() = default;

	static NumericFormatStrategy instance;
	inline static const std::string NumericFormat = "numeric";
};
#endif // !defined(EA_AA77EA40_BD62_4da2_A4B1_24E0543D0FA7__INCLUDED_)
