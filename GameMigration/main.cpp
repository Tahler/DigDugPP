
#include "Core.h"
#include "Character.h"
#include "World.h"
#include "Blocks.h"
#include "Window.h"

using namespace std;

World world;
Character player(&world, 1, 3);

////////////////////////////////////////////////////////////

bool update(float dt)
{
	//tri.isColliding = (!tri.getBoundingBox().intersects(rect));
	world.update();
	player.update();
	return false;
}

void draw(Core::Graphics& graphics)
{
	//graphics.SetBackgroundColor(RGB(127, 127, 127));
	world.draw(graphics);
	player.draw(graphics);
}

void main()
{
	Core::Init("DigDug++", WINDOW_WIDTH, WINDOW_HEIGHT);
	Core::RegisterUpdateFn(update);
	Core::RegisterDrawFn(draw);
	Core::GameLoop();
}