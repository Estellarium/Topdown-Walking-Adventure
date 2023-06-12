#pragma once
#include <sstream>
#include <combaseapi.h>
#include "Constants.h"

struct colorRGB {
	int R = 0;
	int G = 0;
	int B = 0;
};

interface IBlocking {
protected:
	bool block = true;
public:
	virtual bool isBlocking() {
		return block;
	}
};

class GameObject {
protected:
	char symbol = ' ';
	int fgColor = 0x000000;
	int bgColor = 0x000000;
	std::stringstream fg;
	std::stringstream bg;

	colorRGB parseColor(int hex);
	std::stringstream colorToString(colorRGB color);
public:
	//Methods
	virtual void onCollision(GameObject* obj) {}
	virtual void onOverlap(GameObject* obj) {}

	//Rendering
	virtual std::stringstream getFullColor();
	std::stringstream getForegroundColor();
	std::stringstream getBackgroundColor();
	std::stringstream getInverseForegroundColor();
	std::stringstream getInverseBackgroundColor();
	virtual std::stringstream getRender();
};