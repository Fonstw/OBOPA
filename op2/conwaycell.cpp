//
// Created by fonst on Sep 25.
//

#include "conwaycell.h"

void ConwayCell::SetAlive(bool state)
{
	alive = state;
}

bool ConwayCell::GetAlive()
{
	return alive;
}

bool ConwayCell::DeadYet(int neighbours)
{
	// return whether cell is dead het
	return neighbours<min || neighbours>max;
}

bool ConwayCell::BornAgain(int neighbours)
{
	// return whether cell is (re-)born
	return neighbours == born;
}
