// ====== INCLUDES ======
#include <iostream>
#include <string>
#include <time.h>
#include <cstring>
//#include <vector>
#include "highlife.h"

// ====== DEFINES ======
#define GRID_SIZE 25
#define LAST_GENERATION 100
#define DENSITY 3

// ====== THIS THING ======
using namespace std;

// ====== VARIABLES ======
int currentGeneration = 0;

// ====== CLASSES ======
HighLifeCell grid[GRID_SIZE][GRID_SIZE];

// ====== METHODS ======
int CountNeighbours(int xPos, int yPos)
{
	int neighbours = 0;

	// for anything left, center or right from it...
	for (int x=-1; x<=1; x++)
	{
		// ...and anything above, in the middle or under it...
		for (int y=-1; y<=1; y++)
		{
			// Forgive me for the following if-else statement, I know there should be a better way but I can't find it

			// If it's not this cell...
			if (x == 0 && x == y) {}
			// ...and it's not outside of the grid (also that's blasphemy)
			else if (xPos + x >= 0 && xPos + x < GRID_SIZE && yPos + y >= 0 && yPos + y < GRID_SIZE)
			{
				// Count that which lives (through the above we basically select all neighbours of which we then count
				// what's alive)
				if (grid[xPos + x][yPos + y].GetAlive())
					neighbours++;
			}   // end else
		}   // end y
	}

	return neighbours;
}

void LiveAndDie()
{
	// 'Empty' grid to write in, for instantity's sake
	HighLifeCell tempGrid[GRID_SIZE][GRID_SIZE];

	for (int x=0; x<GRID_SIZE; x++)
	{
		for (int y=0; y<GRID_SIZE; y++)
		{
			// Is anything in the grid dead?
			if (grid[x][y].DeadYet(CountNeighbours(x, y)))
				// Say so in the writable grid
				tempGrid[x][y].SetAlive(false);
			// bla bla alive?
			else if (grid[x][y].BornAgain(CountNeighbours(x, y)))
				// bla bla writable grid
				tempGrid[x][y].SetAlive(true);
		}
	}

	// Copy written grid into actual, cout'ed, current grid
	memcpy(grid, tempGrid, sizeof(tempGrid));
}

void PrintGrid()
{
	// For each in the grid
	for (auto &x : grid)
	{
		for (auto &y : x)
		{
			// Print X on live cells and . on dead cells
			if (y.GetAlive())
				cout<<"X";
			else
				cout<<".";
		}   // end y
		cout<<endl;
	}
}

int main()
{
	// Initialise a random field through a very bad manner, but that's not too important now
	srand(time(NULL));

	for (auto &x : grid)
	{
		for (auto &y : x)
			y.SetAlive(rand()%DENSITY == 0);
	}

	// The actual Conway's Game of Life'ing starts here!!
	while (currentGeneration < LAST_GENERATION)
	{
		// Tell which generation we're in
		cout<<"Generation: "<<currentGeneration<<endl;

		// Show this generation's cells
		PrintGrid();
		// Kill and birth them
		LiveAndDie();
		// Separate the generations for readability's sake
		cout<<endl;

		// Count generation
		currentGeneration++;
	}
}
