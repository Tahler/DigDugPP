
#include "World.h"
#include "Physics.h"
#include <stdlib.h>

using Physics::Vector;

// Measured in blocks
const int WORLD_WIDTH = 30;
const int WORLD_HEIGHT = 80;

World::World()
{
	blocks = vector<vector<Block*>>(WORLD_WIDTH, vector<Block*>(16));
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
			if (window.box.contains(blocks[i][j]->a)) blocks[i][j]->draw(g);
		}
	}
	//Block* upperLeft = &getBlockAt(window.box.a);
	//Block* lowerRight = &getBlockAt(window.box.b);

	//Point begin = Point(upperLeft->a.x / BLOCK_SIZE, upperLeft->a.y / BLOCK_SIZE);
	//Point end = Point(lowerRight->b.x / BLOCK_SIZE, lowerRight->b.y / BLOCK_SIZE);
	//
	//for (unsigned int i = begin.x; i < end.x; i++)
	//{
	//	for (unsigned int j = begin.y; j < end.y; j++)
	//	{
	//		blocks[i][j]->draw(g);
	//	}
	//}
}
Block& World::getBlockAt(Point& p)
{
	//int x = p.x / BLOCK_SIZE;
	//int y = p.y / BLOCK_SIZE;
	//
	//// Prevent index out of bounds
	//if (p.x >= blocks.size()) x = blocks.size() - 1;
	//if (p.y >= blocks[0].size()) y = blocks[0].size() - 1;
	
	return *blocks[p.x / BLOCK_SIZE][p.y / BLOCK_SIZE];
}