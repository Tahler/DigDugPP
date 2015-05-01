
#include "World.h"
#include <stdlib.h>

// Measured in pixels
const int BLOCK_SIZE = 50;
const int WINDOW_WIDTH = 24 * BLOCK_SIZE;
const int WINDOW_HEIGHT = 16 * BLOCK_SIZE;

// Measured in blocks
const int WORLD_WIDTH = 24;
const int WORLD_HEIGHT = 80;

World::World()
{
	blocks = vector<vector<Block*>>(WORLD_WIDTH, vector<Block*>(16));
	init();
}
World::~World()
{
	for (unsigned int i = 0; i < blocks.size(); i++)
	{
		for (unsigned int j = 0; j < blocks[i].size(); j++) // Leave the first four rows blank.
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
			else blocks[i][j] = new Earth(Point(i, j));
		}
		for (unsigned int j = 6; j < 9; j++)
		{
			(rand() % 2 == 0) ? blocks[i][j] = new Earth(Point(i, j)) : blocks[i][j] = new Earth2(Point(i, j));
		}
		for (unsigned int j = 9; j < blocks[i].size(); j++)
		{
			blocks[i][j] = new Earth2(Point(i, j));
		}
	}
	delete blocks[10][4];
	blocks[10][4] = new Grass(Point(10, 4));
	delete blocks[11][5];
	blocks[11][5] = new Cave(Point(11, 5));
	delete blocks[3][4];
	blocks[3][4] = new Stone(Point(3, 4));
	delete blocks[3][5];
	blocks[3][5] = new Copper(Point(3, 5));
	delete blocks[3][6];
	blocks[3][6] = new Iron(Point(3, 6));
	delete blocks[3][7];
	blocks[3][7] = new Silver(Point(3, 7));
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
	for (unsigned int i = 0; i < blocks.size(); i++)
	{
		for (unsigned int j = 0; j < blocks[0].size(); j++)
		{
			blocks[i][j]->draw(g);
		}
	}
}
Block& World::getBlockAt(Point& a) // consider returning Block&
{
	return *blocks[a.x / BLOCK_SIZE][a.y / BLOCK_SIZE];
}