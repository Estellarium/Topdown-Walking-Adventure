#pragma once
#include "Input.h"
#include <Windows.h>

inputValues getInput() {
#define Key(key) (GetKeyState(key) & 0x8000)
#define v static_cast<int>
	inputValues input;
	input.x = v(Key(VK_RIGHT) || Key('D')) - v(Key(VK_LEFT) || Key('A'));
	input.y = v(Key(VK_DOWN) || Key('S')) - v(Key(VK_UP) || Key('W'));
	if (Key('P') > 1 && !pausePressed) {
		prevPauseState = !prevPauseState;
		pausePressed = true;
	}
	else if (Key('P') == 0) {
		pausePressed = false;
	}
	input.pause = prevPauseState;

	input.restart = Key('R') > 1;
	input.close = Key(VK_ESCAPE) > 1;
	input.start = Key(VK_SPACE) > 1;
	return input;
}
#undef v
#undef Key