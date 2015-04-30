
#include "World.h"

// Measured in pixels
const int BLOCK_SIZE = 50;
const int WINDOW_WIDTH = 24 * BLOCK_SIZE;
const int WINDOW_HEIGHT = 16 * BLOCK_SIZE;

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
			//if (j == 3 && i < 6) blocks[i][j] = new Earth(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
			/*else*/ blocks[i][j] = new Sky(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
		}
		for (unsigned int j = 4; j < blocks[i].size(); j++) // Rest of the world is ground
		{
			if (j == 4 && i >= 6 && i <= 18) blocks[i][j] = new Cave(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
			else if (j==4 || j == 3) blocks[i][j] = new Grass(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
				else blocks[i][j] = new Earth(Point(i * BLOCK_SIZE, j * BLOCK_SIZE));
		}
	}
	delete blocks[10][4];
	blocks[10][4] = new Grass(Point(10 * BLOCK_SIZE, 4 * BLOCK_SIZE));
	delete blocks[3][4];
	blocks[3][4] = new Stone(Point(3 * BLOCK_SIZE, 4 * BLOCK_SIZE));
	delete blocks[3][5];
	blocks[3][5] = new Copper(Point(3 * BLOCK_SIZE, 5 * BLOCK_SIZE));
	delete blocks[3][6];
	blocks[3][6] = new Iron(Point(3 * BLOCK_SIZE, 6 * BLOCK_SIZE));
	delete blocks[3][7];
	blocks[3][7] = new Silver(Point(3 * BLOCK_SIZE, 7 * BLOCK_SIZE));
	delete blocks[2][5];
	blocks[2][5] = new Ladder(Point(2 * BLOCK_SIZE, 5 * BLOCK_SIZE));
	delete blocks[2][6];
	blocks[2][6] = new Ladder(Point(2 * BLOCK_SIZE, 6 * BLOCK_SIZE));
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