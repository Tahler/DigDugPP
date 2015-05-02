#ifndef _INPUT_H_
#define _INPUT_H_

#include "Core.h"

namespace Core
{

class CORE_SHARED Input
{
public:

	static const int KEY_LEFT	= VK_LEFT;
	static const int KEY_RIGHT	= VK_RIGHT;
	static const int KEY_UP		= VK_UP;
	static const int KEY_DOWN	= VK_DOWN;
	static const int KEY_ESCAPE	= VK_ESCAPE;
	static const int BUTTON_LEFT	= VK_LBUTTON;
	static const int BUTTON_RIGHT	= VK_RBUTTON;
	static const int KEY_S   = 0x53;
	static const int KEY_A   = 0x41;
	static const int KEY_W   = 0x57;
	static const int KEY_D   = 0x44;

	static bool IsPressed( int key );
	static void GetMousePos( int& x, int& y );
	static int GetMouseX();
	static int GetMouseY();
};

} // namespace Engine

#endif // _INPUT_H_