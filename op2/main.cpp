// ====== INCLUDES ======
#include <iostream>
#include <string>
#include <time.h>
//#include <vector>
#include "cell.h"

// ====== DEFINES ======
#define GRID_SIZE 6
#define ROUND_COUNT 24

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
			else
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
	memcpy(tempGrid, grid, sizeof(grid));

	for (int x=0; x<GRID_SIZE; x++)
	{
		for (int y=0; y<GRID_SIZE; y++)
		{
			if (tempGrid[x][y].DeadYet(CountNeighbours(x, y)))
				tempGrid[x][y].SetAlive(false);
			else if (tempGrid[x][y].BornAgain(CountNeighbours(x, y)))
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
			y.SetAlive(rand()%4 == 0);
	}

	while (currentGeneration < ROUND_COUNT)
	{
		cout<<"Generation: "<<currentGeneration<<endl;
		PrintGrid();
		LiveAndDie();
		currentGeneration++;
		cout<<endl;
	}
}
