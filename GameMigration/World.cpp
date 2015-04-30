
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
	
}
void World::init()
{
	for (unsigned int i = 0; i < blocks.size(); i++)
	{
		for (unsigned int j = 0; j < blocks[i].size(); j++) // Leave the first four rows blank.
		{
			blocks[i][j] = new Earth(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
		}
	}
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