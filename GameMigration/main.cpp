#include "Core.h"
#include "Sound.h"
#include "Character.h"
#include "World.h"
#include "Window.h"
#include "Store.h"

int invItems[8] = {0, 0, 0, 0, 0, 0, 0, 0};
Inventory Character::inventory = Inventory(10, invItems, 0, 0);
World world;
Character player(world);
Store store(player);

////////////////////////////////////////////////////////////

bool update(float dt)
{
	// Move the player
	if (!player.storeOpen) player.update();
	else store.update();

	// Sidescroll the window
	world.window.update();

	return false;
}

void draw(Core::Graphics& graphics)
{
	world.draw(graphics);
	if (!world.shouldFlash) player.draw(graphics);
	if (player.storeOpen) store.draw(graphics);
	
}

void main()
{
	Core::Init("DigDug++", WINDOW_WIDTH, WINDOW_HEIGHT);
	Core::RegisterUpdateFn(update);
	Core::RegisterDrawFn(draw);

	Sound::playMusic();

	Core::GameLoop();
}