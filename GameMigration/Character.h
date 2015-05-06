
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Physics.h"
#include "World.h"
#include "Inventory.h"
//#include <string.h>

using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;
using std::string;

class Character
{
private:
	static Point spawnPoint;
	World* world; // WORLD-STAR

public:
	static Inventory inventory;
	Point location; // The upper left corner of his block
	Vector velocity;
	bool isJumping;
	bool isOnLadder;
	bool storeOpen;
	static string notification;

	Character() :
		world(nullptr),
		location(0, 0),
		velocity(0, 0),
		isJumping(false),
		isOnLadder(false),
		storeOpen(false)	
	{}

	Character(World* world);

	Physics::Rectangle getBoundingBox();
	Point getCenterPoint();
	void setLocation(Point&);
	
	void checkKeyInput();
	void reset();
	void jump();
	void moveX();
	void moveY();
	void mine(int dir);

	void update();
	void draw(Core::Graphics&);
	void drawAt(Core::Graphics&, Vector&);
};

#endif