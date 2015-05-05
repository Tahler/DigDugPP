
#include "Core.h"
#include "Character.h"
#include "World.h"
#include "Blocks.h"
#include "Window.h"
#include "Store.h"

using namespace std;

int invItems[8] = {0, 0, 0, 0, 0, 0, 0, 0};
Inventory Character::inventory = Inventory(10, invItems, 0);
World world;
Character player(&world, 4, 3);
Store store;

////////////////////////////////////////////////////////////

bool update(float dt)
{
	//tri.isColliding = (!tri.getBoundingBox().intersects(rect));
	world.update();
	player.update();
	//store.update();
	return false;
}

void draw(Core::Graphics& graphics)
{
	//graphics.SetBackgroundColor(RGB(127, 127, 127));
	world.draw(graphics);
	player.draw(graphics);
	//store.draw(graphics);
}

void main()
{
	Core::Init("DigDug++", WINDOW_WIDTH, WINDOW_HEIGHT);
	Core::RegisterUpdateFn(update);
	Core::RegisterDrawFn(draw);
	Core::GameLoop();
}