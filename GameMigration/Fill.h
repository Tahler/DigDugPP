
#ifndef FILL_H
#define FILL_H

#include "Core.h"
#include "Physics.h"

void fillSquare(Core::Graphics& g, Physics::Point p, int width);
void fillRectangle(Core::Graphics& g, Physics::Point p, int width, int height);
void fillHexagon(Core::Graphics& g, Physics::Point p, int width);


#endif