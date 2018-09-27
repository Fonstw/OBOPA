//
// Created by fonst on Sep 25.
//

#include "cell.h"

Cell::~Cell() = default;

void Cell::SetAlive(bool state)
{
	alive = state;
}

bool Cell::GetAlive()
{
	return alive;
}

bool Cell::deadYet(int neighbours)
{
	// return whether cell is dead het
	return neighbours<min || neighbours>max;
}

bool Cell::bornAgain(int neighbours)
{
	// return whether cell is (re-)born
	return neighbours == born;
}
