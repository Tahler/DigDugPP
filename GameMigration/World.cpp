
#include "World.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

const int BLOCK_WIDTH = 50;

const int BLOCKS_PER_WINDOW = (WINDOW_WIDTH / BLOCK_WIDTH) * (WINDOW_HEIGHT / BLOCK_WIDTH);
const int WORLD_SIZE_IN_WINDOWS = 20;

World::World()
{
	blocks = vector<vector<Block>>(24, vector<Block>(16));
	init();
}
void World::init()
{
	for (int i = 0; i < blocks.size(); i++)
	{
		for (int j = 0; j < blocks[0].size(); j++)
		{
			blocks[i][j] = Block(Point(i * BLOCK_WIDTH, j * BLOCK_WIDTH));
		}
	}
}
void World::draw(Core::Graphics g)
{
	for (int i = 0; i < blocks.size(); i++)
	{
		for (int j = 0; j < blocks[0].size(); j++)
		{
			blocks[i][j].draw(g);
		}
	}
	// draw character
}
