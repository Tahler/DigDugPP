
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Physics.h"

using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;

class Character
{
public:
	Point location; // The upper left corner of the bounding box
	Vector velocity;
	Vector acceleration;
	bool isColliding;
	bool isJumping;

	Character();
	Character(float, float);

	Physics::Rectangle getBoundingBox();
	void checkKeyInput();
	void move();
	void draw(Core::Graphics);
};

#endif