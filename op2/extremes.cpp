//
// Created by fonst on Sep 25.
//

#include "extremes.h"

bool ExtremesCell::deadYet(int neighbours)
{
	// return whether the amount of neighbours is NOT a viable number for the cell to DIE
	return std::find(life.begin(), life.end(), neighbours) == life.end();
}