///////////////////////////////////////////////////////////
//  LitteralFormatStrategy.cpp
//  Implementation of the Class LitteralFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#include "LitteralFormatStrategy.h"
#include "TimeFormater.h"

LitteralFormatStrategy LitteralFormatStrategy::instance;


LitteralFormatStrategy::LitteralFormatStrategy()
	: FormatStrategy(LitteralFormat)
{
}

std::string LitteralFormatStrategy::format(int time) const 
{
	// À compléter: décomposer la durée et construire une chaine avec en format litéral

	return std::string();
}