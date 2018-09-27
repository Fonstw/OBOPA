//
// Created by fonst on Sep 25.
//

#pragma once

class Cell
{
	protected:
		int min = 2; // still alive
		int max = 3; // still alive
		int born = 3;
		bool alive = false;

	public:
		virtual ~Cell();
		virtual void setAlive(bool state);
		virtual bool getAlive();
		virtual bool deadYet(int neighbours);
		virtual bool bornAgain(int neighbours);
};
