
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
	bool shouldFlash;
	vector<vector<Block*>> blocks;
	Window window;

	World();
	~World();
	void init();
	void addEarth();
	void addMinerals();
	void replaceBlock(int&, int&, int&);
	void switchVals(int&, int&, int&, int&, int&, int&);

	void flash(Core::Graphics&);
	void draw(Core::Graphics&);

	Block& getBlockAt(Point);
	void destroyBlockAt(Point);
	void placeLadderAt(Point);
};

#endif