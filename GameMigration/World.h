
#ifndef WORLD_H
#define WORLD_H

#include "Physics.h"
#include "Blocks.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

const int TILE_WIDTH = 50;

class World
{
public:
	Blocks::Block blocks[]; // change to a vector<block>????
};

#endif