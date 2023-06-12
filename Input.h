#pragma once
#include<Windows.h>

struct inputValues {
	int x = 0;
	int y = 0;
	bool close = false;
	bool pause = false;	
	bool restart = false;
	bool start = false;
};
static bool pausePressed = false;
static bool prevPauseState = false;

inputValues getInput();