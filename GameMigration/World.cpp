
#include "World.h"
#include "Physics.h"
#include <stdlib.h>

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
	for (unsigned int i = 0; i < blocks.size(); i++)
	{
		for (unsigned int j = 0; j < blocks[i].size(); j++)
		{
			delete blocks[i][j];
		}
	}
}
void World::init()
{
	for (unsigned int i = 0; i < blocks.size(); i++)
	{
		for (unsigned int j = 0; j < 4; j++) // Leave the first four rows blank.
		{
			blocks[i][j] = new Sky(Point(i, j));
		}
		for (unsigned int j = 4; j < 6; j++) 
		{
			if (j == 4 && i >= 6 && i <= 18) blocks[i][j] = new Cave(Point(i, j));
			else if (j==4 || j == 3) blocks[i][j] = new Grass(Point(i, j));
			else blocks[i][j] = new Dirt(Point(i, j));
		}
		for (unsigned int j = 6; j < 9; j++)
		{
			(rand() % 2 == 0) ? blocks[i][j] = new Dirt(Point(i, j)) : blocks[i][j] = new Stone(Point(i, j));
		}
		for (unsigned int j = 9; j < blocks[i].size(); j++)
		{
			blocks[i][j] = new Stone(Point(i, j));
		}
	}
	for (unsigned int i = 4; i < 16; i++)
	{
		delete blocks[5][i];
		blocks[5][i] = new Cave(Point(5, i));
	}
	delete blocks[10][4];
	blocks[10][4] = new Grass(Point(10, 4));
	delete blocks[11][5];
	blocks[11][5] = new Cave(Point(11, 5));
	delete blocks[3][5];
	blocks[3][5] = new Copper(Point(3, 5));
	delete blocks[3][6];
	blocks[3][6] = new Iron(Point(3, 6));
	delete blocks[3][7];
	blocks[3][7] = new Silver(Point(3, 7));
	delete blocks[3][8];
	blocks[3][8] = new Sapphire(Point(3, 8));
	delete blocks[3][9];
	blocks[3][9] = new Ruby(Point(3, 9));
	delete blocks[3][10];
	blocks[3][10] = new Emerald(Point(3, 10));
	delete blocks[3][11];
	blocks[3][11] = new Gold(Point(3, 11));
	delete blocks[3][12];
	blocks[3][12] = new Diamond(Point(3, 12));
	delete blocks[2][5];
	blocks[2][5] = new Ladder(Point(2, 5));
	delete blocks[2][6];
	blocks[2][6] = new Ladder(Point(2, 6));
}
void World::update()
{
	
}
void World::draw(Core::Graphics& g)
{
	// Select all blocks on the screen and draw them //
	Block* upperLeft = &getBlockAt(window.box.a);
	Block* lowerRight = &getBlockAt(window.box.b);

	Point begin = Point(upperLeft->a.x / BLOCK_SIZE, upperLeft->a.y / BLOCK_SIZE);
	Point end = Point(lowerRight->a.x / BLOCK_SIZE, lowerRight->a.y / BLOCK_SIZE);

	for (unsigned int i = begin.x; i <= end.x; i++)
	{
		for (unsigned int j = begin.y; j <= end.y; j++)
		{
			blocks[i][j]->drawAt(g, window.box.a);
		}
	}
}
Block& World::getBlockAt(Point& p)
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

void World::destroyBlockAt(Point& a)
{
	int x = a.x / BLOCK_SIZE; 
	int y = a.y / BLOCK_SIZE;
	delete blocks[x][y];
	blocks[x][y] = new Cave(Point(x, y));
}
