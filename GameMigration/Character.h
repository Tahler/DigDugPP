
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Physics.h"
#include "World.h"

using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;

class Character
{
private:
	World* world; // WORLD-STAR

public:
	Point location; // The upper left corner of the bounding box
	Vector velocity;
	bool isColliding;
	bool isJumping;

	Character() :
		world(NULL),
		location(0, 0),
		velocity(0, 0),
		isColliding(false),
		isJumping(false)
	{}
	Character(World* w, float x, float y) : 
		world(w),
		location(x, y),
		velocity(0, 0),
		isColliding(false),
		isJumping(false)
	{}

	Physics::Rectangle getBoundingBox();
	void checkKeyInput();
	void jump();
	void checkCollisions();
	void move();

	void update();
	void draw(Core::Graphics);
};

#endif