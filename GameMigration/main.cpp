#include "Core.h"
#include "Character.h"
#include "World.h"
#include "Window.h"
#include "Store.h"

#include <mmsystem.h>

int invItems[8] = {0, 0, 0, 0, 0, 0, 0, 0};
Inventory Character::inventory = Inventory(10, invItems, 0);
World world;
Character player(&world);
Store store;

////////////////////////////////////////////////////////////

bool update(float dt)
{
	player.update();
	//store.update();
	return false;
}

void draw(Core::Graphics& graphics)
{
	world.draw(graphics);
	if (!world.shouldFlash) player.draw(graphics);
	//store.draw(graphics);
}

void main()
{
	Core::Init("DigDug++", WINDOW_WIDTH, WINDOW_HEIGHT);
	Core::RegisterUpdateFn(update);
	Core::RegisterDrawFn(draw);

	// Loop the music
	PlaySound(TEXT("music.wav"), nullptr, SND_ASYNC | SND_LOOP);

	Core::GameLoop();
}