#include "GameObject.h"
#include <sstream>
#include <combaseapi.h>

colorRGB GameObject::parseColor(int hex) {
	colorRGB ret;
	int R = ((hex >> 16) & 0xFF);
	int G = ((hex >> 8) & 0xFF);
	int B = ((hex) & 0xFF);
	ret = { R,G,B };
	return ret;
}
std::stringstream GameObject::colorToString(colorRGB color) {
	std::stringstream colorCode;
	colorCode << std::to_string(color.R) << ";";
	colorCode << std::to_string(color.G) << ";";
	colorCode << std::to_string(color.B);
	return colorCode;
}
std::stringstream GameObject::getFullColor() {
	std::stringstream ret;
	ret << "\033[38;2;";
	ret << fg.str() << ";48;2;";
	ret << bg.str() << "m";
	return ret;
}
std::stringstream GameObject::getForegroundColor() {
	std::stringstream ret;
	ret << fg.str();
	return ret;
}
std::stringstream GameObject::getBackgroundColor() {
	std::stringstream ret;
	ret << bg.str();
	return ret;
}
std::stringstream GameObject::getInverseForegroundColor() {
	std::stringstream ret;
	colorRGB fgColorRGB = parseColor(fgColor);
	ret << colorToString({
		255 - fgColorRGB.R, 
		255 - fgColorRGB.G,
		255 - fgColorRGB.B
		}
	).str();
	return ret;
}
std::stringstream GameObject::getInverseBackgroundColor() {
	std::stringstream ret;
	colorRGB bgColorRGB = parseColor(bgColor);
	ret << colorToString({
		255 - bgColorRGB.R,
		255 - bgColorRGB.G,
		255 - bgColorRGB.B
		}
	).str();
	return ret;
}
std::stringstream GameObject::getRender() {
	std::stringstream ret;
	std::string pad = "";
	for (int i = 1; i <= padding; i++) pad += ' ';
		ret << getFullColor().str();
	ret << pad << symbol << pad;
	return ret;
}
