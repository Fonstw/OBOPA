//
// Created by fonst on Sep 25.
//

#pragma once

#include <vector>
#include "cell.h"
using namespace std;

class HighLifeCell : public Cell
{
	protected:
		vector<int> born {3, 6};

	public:
		HighLifeCell();
		bool BornAgain(int neighbours) override;
};
