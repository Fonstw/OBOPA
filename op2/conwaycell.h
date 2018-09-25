//
// Created by fonst on Sep 25.
//

#pragma once

#include "cell.h"

class ConwayCell : public Cell
{
public:
	void SetAlive(bool state) override;
	bool GetAlive() override;
	bool DeadYet(int neighbours) override;
	bool BornAgain(int neighbours) override;
};
