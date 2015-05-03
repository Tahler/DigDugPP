
#include "Character.h"

#include "Core.h"
#include "Physics.h"
#include "World.h"
#include <time.h>

using Physics::Gravity;
using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;
using Physics::operator+;
using Physics::operator-;

// Character //
const float MAX_SPEED = BLOCK_SIZE / 10;
const float DRAG = 0.1;

long lastMineMillis = time(0) * 1000;
int pickStrength = 3;

Physics::Rectangle Character::getBoundingBox()
{
	return Physics::Rectangle(Point(location.x + BLOCK_FIFTH, location.y + 2), Point(location.x + BLOCK_SIZE - BLOCK_FIFTH, location.y + BLOCK_SIZE - 2));
	//return Physics::Rectangle(Point(location.x + 2, location.y + 2), Point(location.x + BLOCK_SIZE - 2, location.y + BLOCK_SIZE - 2));
}
void Character::checkKeyInput()
{
	if (Core::Input::IsPressed(Core::Input::KEY_A)) 
	{
		velocity.x = -MAX_SPEED;
		mine(1);
	}
	else if (Core::Input::IsPressed(Core::Input::KEY_D)) 
	{
		velocity.x = MAX_SPEED;
		mine(3);
	}
	else
	{
		velocity.x = 0;
		if (Core::Input::IsPressed(Core::Input::KEY_W)) 
		{
			jump();
			mine(2);
		}
		else if (Core::Input::IsPressed(Core::Input::KEY_S)) 
		{
			mine(0);
		}
	}
}
void Character::jump()
{
	if (!isJumping)
	{
		isJumping = true;
		velocity.y = -sqrt(2 * Gravity::acceleration * BLOCK_SIZE);
	}
}
void Character::checkCollisions()
{
	// No matter what direction, there are two corners that have to be checked.
	Block* neighbor1;
	Block* neighbor2;
	Physics::Rectangle* box = &getBoundingBox();
	/*box->a.x = (int) box->a.x;
	box->a.y = (int) box->a.y;
	box->b.x = (int) box->b.x;
	box->b.y = (int) box->b.y;*/

	if (velocity.y > 0) // moving down
	{
		isJumping = true; // If the character is falling he should not be able to jump

		neighbor1 = &(world->getBlockAt(Point(box->a.x, box->b.y + MAX_SPEED - 1)));
		neighbor2 = &(world->getBlockAt(Point(box->b.x, box->b.y + MAX_SPEED - 1)));
		if (!neighbor1->isTraversable || !neighbor2->isTraversable)
		{
			isJumping = false;
			velocity.y = 0;
			shift(Vector(0, neighbor1->a.y - box->b.y - 1)); // -3 = -1 for buffer and -2 for hitbox buffer
			//location.y = neighbor1->a.y - BLOCK_SIZE - 1;
		}
	}
	else if (velocity.y < 0) // moving up
	{
		neighbor1 = &(world->getBlockAt(Point(box->a.x, box->a.y - MAX_SPEED + 1)));
		neighbor2 = &(world->getBlockAt(Point(box->b.x, box->a.y - MAX_SPEED + 1)));
		if (!neighbor1->isTraversable || !neighbor2->isTraversable)
		{
			velocity.y = 0;
			shift(Vector(0, neighbor1->b.y - box->a.y));
			//location.y = neighbor1->b.y;
		}
	}

	if (velocity.x < 0) // moving left
	{
		neighbor1 = &(world->getBlockAt(Point(box->a.x - MAX_SPEED + 1, box->a.y)));
		neighbor2 = &(world->getBlockAt(Point(box->a.x - MAX_SPEED + 1, box->b.y)));
		if (!neighbor1->isTraversable || !neighbor2->isTraversable) // collision incoming
		{
			velocity.x = 0;
			shift(Vector(neighbor1->b.x - box->a.x, 0));
			//location.x = neighbor1->b.x; // it does not matter which neighbor we set the location to
		}
	}
	else if (velocity.x > 0) // moving right
	{
		neighbor1 = &(world->getBlockAt(Point(box->b.x + MAX_SPEED, box->a.y)));
		neighbor2 = &(world->getBlockAt(Point(box->b.x + MAX_SPEED, box->b.y)));
		if (!neighbor1->isTraversable || !neighbor2->isTraversable) 
		{
			velocity.x = 0;
			shift(Vector(neighbor1->a.x - box->b.x - 1, 0));
			//location.x = neighbor1->a.x - BLOCK_SIZE - 1;
		}
	}
}
void Character::shift(Vector& displacement)
{
	location += displacement;
}
void Character::mine(int dir)
{		
	if ((time(0) - lastMineMillis) > 100)
	{
		Physics::Rectangle* box = &getBoundingBox();

		Block* b;
		switch (dir)
		{
		case 0:
			//down
			b = &(world->getBlockAt(Point(box->a.x + BLOCK_HALF, box->b.y + MAX_SPEED - 1)));
			break;
		case 1:
			//right
			b = &(world->getBlockAt(Point(box->a.x - MAX_SPEED + 1, box->a.y + BLOCK_HALF)));
		
			break;
		case 2:
			//up
			b = &(world->getBlockAt(Point(box->a.x + BLOCK_HALF, box->a.y - MAX_SPEED + 1)));
			break;
		case 3:
			//left
			b = &(world->getBlockAt(Point(box->b.x + MAX_SPEED, box->a.y + BLOCK_HALF)));
			break;
		}
	
		BreakableBlock* b2 = dynamic_cast<BreakableBlock*>(b);
		if (b2 != NULL)
		{
			b2->takeDamage(pickStrength);
			if (b2->durability <= 0)
			{
				world->destroyBlockAt(b->a);
			}
		}
		lastMineMillis = time(0) * 1000;
	}
	
}
void Character::move()
{
	// Don't go outside the window, otherwise allow movement
	//if (location.x >= 0 && location.x + BLOCK_SIZE <= WINDOW_WIDTH - MAX_SPEED -4) location.x += velocity.x;
	//else if (location.x >= 0)location.x -= 1;
	//else location.x +=1;
	//if (location.y >= 0 && location.y + BLOCK_SIZE <= WINDOW_HEIGHT) location.y += velocity.y;

	// Move the window if needed
	Window* window = &(world->window); // The larger, viewable screen
	Physics::Rectangle* deadzone = &(world->window.deadzone); // The invisible small box that the character cannot move out of
	Physics::Rectangle* character = &(getBoundingBox()); // The character's bounding box
	
	// if the character is outside the deadzone, shift the window (which also shifts the deadzone)
	if (character->a.x < deadzone->a.x) window->shift(Vector(character->a.x - deadzone->a.x, 0));
	else if (character->b.x > deadzone->b.x) window->shift(Vector(character->b.x - deadzone->b.x, 0));
	if (character->a.y < deadzone->a.y) window->shift(Vector(0, character->a.y - deadzone->a.y));
	else if (character->b.y > deadzone->b.y) window->shift(Vector(0, character->b.y - deadzone->b.y));

	location += velocity;
}
void Character::update()
{
	checkKeyInput();
	checkCollisions();
	move();
	
	// Adjust for gravity
	velocity.y += Gravity::acceleration;
}
void Character::draw(Core::Graphics& g)
{
	drawAt(g, world->window.box.a);
}
void Character::drawAt(Core::Graphics& g, Vector& displacement)
{
	Point p = location - displacement;

	g.SetColor(RGB(28, 212, 52));

	fillSquare(g, Point(p.x + BLOCK_FIFTH * 2, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
	fillSquare(g, Point(p.x + BLOCK_FIFTH * 2, p.y + BLOCK_FIFTH*2), BLOCK_FIFTH);

	g.SetColor(RGB(247, 214, 143));
	fillSquare(g, Point(p.x + 2 * BLOCK_FIFTH, p.y), BLOCK_FIFTH);

	// Hands
	if(velocity.x > 0)
	{
		//fillSquare(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
		fillSquare(g, Point(p.x + 4 * BLOCK_FIFTH, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
		g.SetColor(RGB(28, 212, 52));
		fillSquare(g, Point(p.x + BLOCK_FIFTH * 3, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
	} 
	else if (velocity.x < 0)
	{
		fillSquare(g, Point(p.x, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
		//fillSquare(g, Point(p.x + 3 * BLOCK_FIFTH, p.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
		g.SetColor(RGB(28, 212, 52));
		fillSquare(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
	} 
	else 
	{

		fillSquare(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
		fillSquare(g, Point(p.x + 3 * BLOCK_FIFTH, p.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
		g.SetColor(RGB(28, 212, 52));
		fillSquare(g, Point(p.x + BLOCK_FIFTH * 3, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
		fillSquare(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
	}
	g.SetColor(RGB(38, 88, 158));
	fillRectangle(g, Point(p.x + BLOCK_FIFTH * 2, p.y + BLOCK_FIFTH * 3), BLOCK_FIFTH, BLOCK_FIFTH * 2);
	g.SetColor(RGB(10, 10, 255));

	getBoundingBox().draw(g);
}
