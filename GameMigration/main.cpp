
#include "Core.h"
#include "Physics.h"
using namespace Physics;

Physics::Rectangle rect(Point(350, 500), Point(450, 600));
Triangle tri(Point(350, 400), Point(400, 350), Point(450, 400));

void checkKeyInput()
{
	float pushAcceleration = 0.2f;
	
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT)) tri.acceleration.x = -pushAcceleration;
	else if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)) tri.acceleration.x = pushAcceleration;
	else tri.acceleration.x = 0;

	if (Core::Input::IsPressed(Core::Input::KEY_UP)) tri.acceleration.y = -pushAcceleration;
	else if (Core::Input::IsPressed(Core::Input::KEY_DOWN)) tri.acceleration.y = pushAcceleration;
	else tri.acceleration.y = 0;
}
////////////////////////////////////////////////////////////
bool update(float dt)
{
	checkKeyInput();
	tri.isColliding = (!tri.getBoundingBox().intersects(rect));
	tri.move();
	return false;
}

void draw(Core::Graphics& graphics)
{
	rect.draw(graphics);
	tri.draw(graphics);
}

void main()
{
	Core::Init("DigDug++", 800, 800);
	Core::RegisterUpdateFn(update);
	Core::RegisterDrawFn(draw);
	Core::GameLoop();
}