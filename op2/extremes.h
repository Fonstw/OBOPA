//
// Created by fonst on Sep 25.
// Life formula: 16/6
// Based off http://www.conwaylife.com/w/index.php?title=Conway%27s_Game_of_Life#Variations_on_Life
//

#pragma once

#include <algorithm>
#include <vector>
#include "cell.h"

using namespace std;

class ExtremesCell : public Cell
{
public:
	bool DeadYet(int neighbours) override;

protected:
	vector<int> life = {1, 6};
	int born = 6;
};
