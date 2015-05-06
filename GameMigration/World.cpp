
#include "World.h"
#include "Physics.h"
#include <stdlib.h>
#include <time.h>
#include "Fill.h"

using Physics::Vector;

// Measured in blocks
const int WORLD_WIDTH = 48;
const int WORLD_HEIGHT = 160;

World::World()
{
	blocks = vector<vector<Block*>>(WORLD_WIDTH, vector<Block*>(WORLD_HEIGHT));
	window = Window(Point(0, 0));
	init();
}
World::~World()
{
	for (int i = 0; i < blocks.size(); i++)
	{
		for (int j = 0; j < blocks[i].size(); j++)
		{
			delete blocks[i][j];
		}
	}
}
void World::init()
{
	//srand(time(NULL));
	addEarth();
	addMinerals();
	delete blocks[1][3];
	delete blocks[2][3];
	delete blocks[1][4];
	delete blocks[2][4];
	delete blocks[3][4];
	delete blocks[0][4];
	blocks[1][3] = new StoreLeft(Point(1,3));
	blocks[2][3] = new StoreRight(Point(2,3));
	blocks[2][2]->isTraversable = false;
	blocks[1][4] = new UnbreakableGrass(Point(1,4));
	blocks[2][4] = new UnbreakableGrass(Point(2,4));
	blocks[3][4] = new UnbreakableGrass(Point(3,4));
	blocks[0][4] = new UnbreakableGrass(Point(0,4));
	//delete blocks[10][4];
	//blocks[10][4] = new Grass(Point(10, 4));
	//delete blocks[11][5];
	//blocks[11][5] = new Cave(Point(11, 5));
	//delete blocks[3][5];
	//blocks[3][5] = new Copper(Point(3, 5));
	//delete blocks[3][6];
	//blocks[3][6] = new Iron(Point(3, 6));
	//delete blocks[3][7];
	//blocks[3][7] = new Silver(Point(3, 7));
	//delete blocks[3][8];
	//blocks[3][8] = new Sapphire(Point(3, 8));
	//delete blocks[3][9];
	//blocks[3][9] = new Ruby(Point(3, 9));
	//delete blocks[3][10];
	//blocks[3][10] = new Emerald(Point(3, 10));
	//delete blocks[3][11];
	//blocks[3][11] = new Gold(Point(3, 11));
	//delete blocks[3][12];
	//blocks[3][12] = new Diamond(Point(3, 12));
	
	delete blocks[5][4];
	blocks[5][4] = new Ladder(Point(5, 4));
	delete blocks[5][5];
	blocks[5][5] = new Ladder(Point(5, 5));
	delete blocks[5][6];
	blocks[5][6] = new Ladder(Point(5, 6));
	delete blocks[5][7];
	blocks[5][7] = new Ladder(Point(5, 7));
	delete blocks[5][8];
	blocks[5][8] = new Ladder(Point(5, 8));
	delete blocks[5][9];
	blocks[5][9] = new Ladder(Point(5, 9));
}
void World::addEarth()
{
	for (int i = 0; i < blocks.size(); i++)
	{
		//0-3 100% sky
		for (int j = 0; j < 4; j++) // Leave the first four rows blank.
		{
			blocks[i][j] = new Sky(Point(i, j));
		}
		//4 - 9 100% dirt
		for (int j = 4; j < 9; j++) 
		{
			if (j == 4) blocks[i][j] = new Grass(Point(i, j));
			else blocks[i][j] = new Dirt(Point(i, j));
		}
		//9 - 11 80% dirt 20% stone
		for (int j = 9; j < 20; j++) 
		{
			(rand() % 10 < 2) ? blocks[i][j] = new Stone(Point(i,  j)) : blocks[i][j] = new Dirt(Point(i, j));
		}
		for (int j = 20; j < 40; j++) {
			(rand() % 2 == 0) ? blocks[i][j] = new Stone(Point(i, j)) : blocks[i][j] = new Dirt(Point(i, j));
		}
		for (int j = 40; j < 60; j++) {
			(rand() % 10 < 7) ? blocks[i][j] = new Stone(Point(i, j)) : blocks[i][j] = new Dirt(Point(i, j));
		}
		//20 - end 90% stone
		for (int j = 60; j < 100; j++)
		{
			(rand() % 10 == 0) ? blocks[i][j] = new Dirt(Point(i, j)) : blocks[i][j] = new Stone(Point(i, j));
		}
		for (int j = 100; j < blocks[i].size(); j++)
		{
			(rand() % 20 == 0) ? blocks[i][j] = new Dirt(Point(i, j)) : blocks[i][j] = new Stone(Point(i, j));
		}
	}
}
void World::addMinerals()
{
	int numOccurences;
	int upperBound;
	int lowerBound;
	int minVein;
	int maxVein;
	//Copper
	for (int hh = 0; hh < 8; hh++)
	{
		switchVals(numOccurences, upperBound, lowerBound, minVein, maxVein, hh);
		for (int ii = 0; ii < numOccurences; ii++) 
		{
			int currentVein = (rand() % (maxVein - minVein + 1)) + minVein;
			int currentX = rand() % blocks.size();
			int currentY = (rand() % (lowerBound - upperBound)) + upperBound;
			replaceBlock(currentX, currentY, hh);
			for (int jj = 0; jj < currentVein; jj++) 
			{
				switch (rand() % 4)
				{
				case 0:
					currentX++;
					break;
				case 1:
					currentX--;
					break;
				case 2:
					currentY++;
					break;
				case 3:
					currentY--;
					break;
				}
				//Ensure in bounds
				if(currentX < 0) currentX = 0;
				if (currentY < 0) currentY = 0;
				if (currentX > blocks.size() - 1) currentX = blocks.size() -1;
				replaceBlock(currentX, currentY, hh);
			}
		}

	}
}
void World::replaceBlock(int& x, int& y, int& id)
{
	delete blocks[x][y];
	switch (id)
	{
	case -1:
		blocks[x][y] = new Sky(Point(x, y));
		break;
	case 0:
		//copper
		blocks[x][y] = new Copper(Point(x, y));
		break;
	case 1:
		//iron
		blocks[x][y] = new Iron(Point(x, y));
		break;
	case 2:
		//silver
		blocks[x][y] = new Silver(Point(x, y));
		break;
	case 3:
		//sapphire
		blocks[x][y] = new Sapphire(Point(x, y));
		break;
	case 4:
		//ruby
		blocks[x][y] = new Ruby(Point(x, y));
		break;
	case 5:
		//emerald
		blocks[x][y] = new Emerald(Point(x, y));
		break;
	case 6: 
		//gold
		blocks[x][y] = new Gold(Point(x, y));
		break;
	case 7:
		//diamond
		blocks[x][y] = new Diamond(Point(x, y));
		break;
	}
}
void World::switchVals(int& numOcc, int&  up, int& low, int& minVein, int& maxVein, int& id)
{
	switch (id)
	{
	case 0:
		//copper
		numOcc = 30;
		up = 9;
		low = 50;
		minVein = 2;
		maxVein = 3;
		break;
	case 1:
		//iron
		numOcc = 20;
		up = 30;
		low = 75;
		minVein = 2;
		maxVein = 4;
		break;
	case 2:
		//silver
		numOcc = 30;
		up = 53;
		low = 86;
		minVein = 3;
		maxVein = 4;
		break;
	case 3:
		//sapphire
		numOcc = 20;
		up = 62;
		low = 100;
		minVein = 2;
		maxVein = 3;
		break;
	case 4:
		//ruby
		numOcc = 20;
		up = 85;
		low = 115;
		minVein = 2;
		maxVein = 5;
		break;
	case 5:
		//emerald
		numOcc = 15;
		up = 99;
		low = 130;
		minVein = 2;
		maxVein = 4;
		break;
	case 6: 
		//gold
		numOcc = 20;
		up = 110;
		low = 150;
		minVein = 2;
		maxVein = 3;
		break;
	case 7:
		//diamond
		numOcc = 15;
		up = 120;
		low = 159;
		minVein = 2;
		maxVein = 2;
		break;
	}
}

// Flash the screen for a short time
void World::flash(Core::Graphics& g)
{
	static int count;
	if (shouldFlash)
	{
		if (count == 0) count = 15; // happens when World::draw() calls this function and shouldFlash is suddenly on (Character::reset() did this)
		else
		{
			g.SetColor(RGB(255, 255, 255));
			fillRectangle(g, window.box.a, window.box.b.x - window.box.a.x, window.box.b.y - window.box.a.y);
			count--;
			// if we've just reached the end of the timer, don't flash anymore
			if (count == 0) shouldFlash = false;
		}
	}
}

void World::draw(Core::Graphics& g)
{
	// Select all blocks on the screen and draw them //
	Block* upperLeft = &getBlockAt(window.box.a);
	Block* lowerRight = &getBlockAt(window.box.b);

	Point begin = Point(upperLeft->a.x / BLOCK_SIZE, upperLeft->a.y / BLOCK_SIZE);
	Point end = Point(lowerRight->a.x / BLOCK_SIZE, lowerRight->a.y / BLOCK_SIZE);

	for (int i = begin.x; i <= end.x; i++)
	{
		for (int j = begin.y; j <= end.y; j++)
		{
			blocks[i][j]->drawAt(g, window.box.a);
		}
	}

	flash(g);
}

Block& World::getBlockAt(Point p)
{
	int x = p.x / BLOCK_SIZE;
	int y = p.y / BLOCK_SIZE;
	
	// Prevent index out of bounds
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x >= blocks.size()) x = blocks.size() - 1;
	if (y >= blocks[0].size()) y = blocks[0].size() - 1;
	
	return *blocks[x][y];
}
void World::destroyBlockAt(Point a)
{
	int x = a.x / BLOCK_SIZE; 
	int y = a.y / BLOCK_SIZE;
	delete blocks[x][y];
	blocks[x][y] = new Cave(Point(x, y));
}
