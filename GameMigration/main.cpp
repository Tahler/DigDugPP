
#include "Core.h"
#include "Physics.h"
using namespace Physics;

Physics::Rectangle rect(Vector(350, 500), Vector(450, 600));
Triangle tri(Vector(350, 400), Vector(400, 350), Vector(450, 400));

void checkKeyInput()
{
	float pushAcceleration = 0.2f;
	
	if (Core::Input::IsPressed(Core::Input::KEY_UP)) tri.velocity.y -= pushAcceleration;
	if (Core::Input::IsPressed(Core::Input::KEY_DOWN)) tri.velocity.y += pushAcceleration;
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT)) tri.velocity.x -= pushAcceleration;
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)) tri.velocity.x += pushAcceleration;
}
////////////////////////////////////////////////////////////
bool update(float dt)
{
	checkKeyInput();
	if (!tri.getBoundingBox().intersects(rect)) tri.move();
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