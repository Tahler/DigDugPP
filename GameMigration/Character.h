
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Physics.h"

using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;

class Character
{
public:
	Point location;
	Vector velocity;
	Vector acceleration;
	bool isColliding;
	bool isJumping;

	Character();
	Character(Point&);

	Physics::Rectangle getBoundingBox();
	void move();
	void draw(Core::Graphics);
};

#endif