// ====== INCLUDES ======
#include <iostream>
#include <time.h>
//#include <vector>
#include "cell.h"

// ====== DEFINES ======
#define GRID_SIZE 25
#define LAST_GENERATION 100
#define DENSITY 3

// ====== THIS THING ======
using namespace std;

// ====== VARIABLES ======
int currentGeneration = 0;

// ====== CLASSES ======
Cell grid[GRID_SIZE][GRID_SIZE];

// ====== METHODS ======
int CountNeighbours(int xPos, int yPos)
{
	int neighbours = 0;

	for (int x=-1; x<=1; x++)
	{
		for (int y=-1; y<=1; y++)
		{
			// Forgive me for the following if-else statement, I know there should be a better way but I can't find it
			if (x == 0 && x == y) {}
			else if (xPos + x >= 0 && xPos + x < GRID_SIZE && yPos + y >= 0 && yPos + y < GRID_SIZE)
			{
				if (grid[xPos + x][yPos + y].GetAlive())
					neighbours++;
			}   // end else
		}   // end y
	}

	return neighbours;
}

void LiveAndDie()
{
	Cell tempGrid[GRID_SIZE][GRID_SIZE];

	for (int x=0; x<GRID_SIZE; x++)
	{
		for (int y=0; y<GRID_SIZE; y++)
		{
			if (grid[x][y].DeadYet(CountNeighbours(x, y)))
				tempGrid[x][y].SetAlive(false);
			else if (grid[x][y].BornAgain(CountNeighbours(x, y)))
				tempGrid[x][y].SetAlive(true);
		}
	}

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
	// Initialise a random field
	srand(time(NULL));

	for (auto &x : grid)
	{
		for (auto &y : x)
			y.SetAlive(rand()%DENSITY == 0);
	}

	while (currentGeneration < LAST_GENERATION)
	{
		cout<<"Generation: "<<currentGeneration<<endl;
		PrintGrid();
		LiveAndDie();
		currentGeneration++;
		cout<<endl;
	}
}
