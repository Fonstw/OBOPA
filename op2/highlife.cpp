//
// Created by fonst on Sep 25.
//

#include "highlife.h"

bool HighLifeCell::BornAgain(int neighbours)
{
	// return whether the amount of neighbours is a viable number for the cell to be (re-)born
	return std::find(born.begin(), born.end(), neighbours) != born.end();
}
