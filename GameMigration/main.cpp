
#include "Core.h"
#include "Physics.h"
#include "Character.h"
#include "World.h"
#include "Blocks.h"
using namespace Physics;

//Physics::Rectangle rect(Point(350, 500), Point(450, 600));
//Triangle tri(Point(350, 400), Point(400, 350), Point(450, 400));
Character c(Point(500, 500));
Blocks::Block b1(Point(500, 600), Point(550, 650));

void checkKeyInput()
{
	float pushAcceleration = 0.2f;
	
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT)) c.acceleration.x = -pushAcceleration;
	else if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)) c.acceleration.x = pushAcceleration;
	else c.acceleration.x = 0;

	if (Core::Input::IsPressed(Core::Input::KEY_UP)) c.acceleration.y = -pushAcceleration;
	else if (Core::Input::IsPressed(Core::Input::KEY_DOWN)) c.acceleration.y = pushAcceleration;
	else c.acceleration.y = 0;
}
////////////////////////////////////////////////////////////
bool update(float dt)
{
	checkKeyInput();
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