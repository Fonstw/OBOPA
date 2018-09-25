//
// Created by fonst on Sep 25.
// Life formula: 23/36
//

#pragma once

#include <algorithm>
#include <vector>
#include "cell.h"
using namespace std;

class HighLifeCell : public Cell
{
public:
	bool BornAgain(int neighbours) override;

protected:
	vector<int> born {3, 6};
};
