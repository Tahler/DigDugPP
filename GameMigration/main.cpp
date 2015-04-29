
#include "Core.h"
#include "Character.h"
#include "World.h"
#include "Blocks.h"

//Physics::Rectangle rect(Point(350, 500), Point(450, 600));
//Triangle tri(Point(350, 400), Point(400, 350), Point(450, 400));
Character c(500, 500);
Blocks::Block b1(Point(500, 600), Point(550, 650));

////////////////////////////////////////////////////////////
bool update(float dt)
{
	//tri.isColliding = (!tri.getBoundingBox().intersects(rect));
	c.move();
	return false;
}

void draw(Core::Graphics& graphics)
{
	graphics.SetBackgroundColor(RGB(127, 127, 127));
	b1.draw(graphics);
	c.draw(graphics);
}

extern const int WINDOW_WIDTH, WINDOW_HEIGHT;

void main()
{
	Core::Init("DigDug++", WINDOW_WIDTH, WINDOW_HEIGHT);
	Core::RegisterUpdateFn(update);
	Core::RegisterDrawFn(draw);
	Core::GameLoop();
}