
#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Core.h"
#include "Physics.h"
#include "Blocks.h"
#include "Character.h"

using std::vector;
using namespace Blocks;

extern const int WINDOW_WIDTH, WINDOW_HEIGHT, BLOCK_SIZE;

class World
{
private:
	Character player;

public:
	vector<vector<Block>> blocks;
	
	World();

	void init();
	void draw(Core::Graphics&);

	Block& getBlockAt(Point&);
};

#endif