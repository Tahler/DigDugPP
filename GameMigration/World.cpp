
#include "World.h"

// Measured in pixels
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;
const int BLOCK_SIZE = 50;

// Measured in blocks
const int BLOCKS_PER_WINDOW = (WINDOW_WIDTH / BLOCK_SIZE) * (WINDOW_HEIGHT / BLOCK_SIZE);
const int WORLD_SIZE_IN_WINDOWS = 20;

World::World()
{
	blocks = vector<vector<Block*>>(24, vector<Block*>(16));
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
			if (j == 3 && i < 6) blocks[i][j] = new Earth(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
			else blocks[i][j] = new Sky(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
		}
		for (unsigned int j = 4; j < blocks[i].size(); j++) // Rest of the world is ground
		{
			if (j == 4 && i >= 6 && i <= 18) blocks[i][j] = new Cave(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
			else blocks[i][j] = new Earth(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
		}
	}
	delete blocks[10][4];
	blocks[10][4] = new Earth(Point(10 * BLOCK_SIZE, 4 * BLOCK_SIZE));
	blocks[3][4] = new Stone(Point(150, 200));
	blocks[3][5] = new Copper(Point(150, 250));
	blocks[3][6] = new Iron(Point(150, 300));
	blocks[3][7] = new Silver(Point(150, 350));
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