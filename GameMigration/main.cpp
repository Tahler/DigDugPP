
#include "Core.h"
#include "Character.h"
#include "World.h"
#include "Window.h"

using namespace std;

int invItems[8] = {0, 0, 0, 0, 0, 0, 0, 0};
Inventory Character::inventory = Inventory(10, invItems, 0);
World world;
Character player(&world, 3, 3);

////////////////////////////////////////////////////////////

bool update(float dt)
{
	player.update();
	return false;
}

void draw(Core::Graphics& graphics)
{
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