
#ifndef FILL_H
#define FILL_H

#include "Core.h"
#include "Physics.h"

void fillSquare(Core::Graphics& g, Physics::Point p, int width);
void fillRectangle(Core::Graphics& g, Physics::Point p, int width, int height);
void fillTriangle(Core::Graphics& g, Physics::Point p, int width);
void fillHexagon(Core::Graphics& g, Physics::Point p, int width);
void fillOctagon(Core::Graphics& g, Physics::Point p, int width);
void fillCircle(Core::Graphics& g, Physics::Point p, int width);

#endif