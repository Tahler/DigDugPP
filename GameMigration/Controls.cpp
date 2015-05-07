
#include "Controls.h"
#include <input.h>

bool keyPressed(int key)
{
	return Core::Input::IsPressed(key);
}

const int MOVE_UP = 0x57;						// W
const int MOVE_LEFT = 0x41;						// A
const int MOVE_DOWN = 0x53;						// s
const int MOVE_RIGHT = 0x44;					// D
const int MINE_MODE = VK_SHIFT;					// Shift
const int PLACE_LADDER = 0x45;					// E
const int DIE = VK_BACK;						// Backspace
const int OPEN_SHOP = VK_RETURN;				// Enter
const int BUY_ITEM = VK_RETURN;					// Enter
const int EXIT_SHOP = VK_ESCAPE;				// Escape