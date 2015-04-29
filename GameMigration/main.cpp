
#include "Core.h"
#include "Character.h"
#include "World.h"
#include "Blocks.h"

//Physics::Rectangle rect(Point(350, 500), Point(450, 600));
//Triangle tri(Point(350, 400), Point(400, 350), Point(450, 400));
Character c(0, 0);
Blocks::Block b1(Point(0, 100));
Blocks::Block b2(Point(50, 100));
Blocks::Block b3(Point(100, 100));
Blocks::Block b4(Point(100, 150));
Blocks::Block b5(Point(150, 150));
Blocks::Block b6(Point(200, 150));

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
	b2.draw(graphics);
	b3.draw(graphics);
	b4.draw(graphics);
	b5.draw(graphics);
	b6.draw(graphics);
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