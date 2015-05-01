
#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Core.h"
#include "Physics.h"
#include "Blocks.h"
#include "Window.h"

using std::vector;
using namespace Blocks;

extern const int WORLD_WIDTH, WORLD_HEIGHT;

class World
{
public:
	vector<vector<Block*>> blocks;
	Window window;

	World();
	~World();
	void init();

	void update();
	void draw(Core::Graphics&);

	Block& getBlockAt(Point&);
};

#endif