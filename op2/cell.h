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
		virtual void SetAlive(bool state);
		virtual bool GetAlive();
		virtual bool DeadYet(int neighbours);
		virtual bool BornAgain(int neighbours);
};
