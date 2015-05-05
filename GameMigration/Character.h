
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Physics.h"
#include "World.h"
#include "Inventory.h"

using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;

class Character
{ // it may be necessary to eventually have a bool moving left, right, up, down for optimization (do this instead of checking velocities every frame)
private:
	World* world; // WORLD-STAR
	Inventory inventory;

public:
	Point location; // The upper left corner of his block
	Vector velocity;
	bool isColliding;
	bool isJumping;

	Character() :
		world(nullptr),
		location(0, 0),
		velocity(0, 0),
		isColliding(false),
		isJumping(false)
	{}
	Character(World* world, float x, float y, int invSize, int items[8], int money);
	Physics::Rectangle getBoundingBox();
	void checkKeyInput();
	void jump();
	void checkCollisions();
	void shift(Vector&);
	void move();
	void mine(int dir);

	void update();
	void draw(Core::Graphics&);
	void drawAt(Core::Graphics&, Vector&);
};

#endif