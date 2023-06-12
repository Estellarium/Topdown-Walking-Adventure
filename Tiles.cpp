#pragma once
#include "Tiles.h"
#include "Player.h";

//Park Tiles
grass::grass() {
	symbol = '±';
	fgColor = 0xFFB676;
	bgColor = 0xFF9282;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}

tallGrass::tallGrass() {
	symbol = 'W';
	fgColor = 0xFF9282;
	bgColor = 0xFFA37C;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}
std::stringstream tallGrass::getRender() {
	if (animate && rand() % (10 * fps) >= (9 * fps)) { symbol = 'W'; animate = false; }
	else if (rand() % (10 * fps) >= (9 * fps)) { symbol = 'M'; animate = true; }
	return tile::getRender();
}

flower::flower() {
	symbol = '%';
	fgColor = 0xFFFFFF;
	bgColor = 0xFFA37C;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}

tree::tree() {
	symbol = 'P';
	fgColor = 0xFF9282;
	bgColor = 0xD64060;
	bg << colorToString(parseColor(fgColor)).str();
	fg << colorToString(parseColor(bgColor)).str();
	block = true;
}

water::water() {
	symbol = ' ';
	fgColor = 0x57C9D6;
	bgColor = 0x3F929C;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = true;
}
std::stringstream water::getRender() {
	if (animate && rand() % (10*fps) >= (7*fps)) { symbol = ' '; animate = false; }
	else if (rand() % (10*fps) >= (7*fps)) { symbol = '~'; animate = true; }
	return tile::getRender();
}

bridge::bridge() {
	symbol = '|';
	fgColor = 0x82461F;
	bgColor = 0x914F22;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}

//Parking Lot Tiles
asphalt::asphalt() {
	symbol = '¬';
	fgColor = 0x331F07;
	bgColor = 0x4C2F0B;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}

parking::parking() {
	symbol = '|';
	fgColor = 0xFFE97F;
	bgColor = 0x4C2F0B;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}

rock::rock() {
	symbol = '^';
	fgColor = 0xA55A27;
	bgColor = 0x4C2F0B;
	bg << colorToString(parseColor(fgColor)).str();
	fg << colorToString(parseColor(bgColor)).str();
	block = true;
}

sand::sand() {
	symbol = '=';
	fgColor = 0xDD9A3B;
	bgColor = 0x6F4916;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}

cactus::cactus() {
	symbol = 190;//¥
	fgColor = 0xC7FF0F;
	bgColor = 0x6F4916;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = true;
}
void cactus::onCollision(GameObject* obj)  {
	if (Pawn* pawn = dynamic_cast<Pawn*>(obj)) {
		pawn->damage(1);
	}
}

//Mall Tiles
flooring::flooring() {
	symbol = '#';
	fgColor = 0xE8CA71;
	bgColor = 0xF9DA7A;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}

chair::chair() {
	symbol = 'h';
	fgColor = 0x8E5A37;
	bgColor = 0xF9DA7A;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}

table::table() {
	symbol = 'T';
	fgColor = 0x8E5A37;
	bgColor = 0xF9DA7A;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = true;
}

plant::plant() {
	symbol = 244; //¶
	fgColor = 0x0AB26C;
	bgColor = 0xF9DA7A;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = true;
}

wall::wall() {
	symbol = ' ';
	fgColor = 0x935D00;
	bgColor = 0xFFA500;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = true;
}

toilet::toilet() {
	symbol = 'h';
	fgColor = 0xFFFFFF;
	bgColor = 0xF9DA7A;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}

clothes::clothes() {
	symbol = 'U';
	fgColor = 0xDB2F4E;
	bgColor = 0xF9DA7A;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = false;
}
void clothes::onOverlap(GameObject* obj) {
	if (Player* p = dynamic_cast<Player*>(obj))
		p->colorize(getForegroundColor());
}

food::food() {
	symbol = 'o';
	fgColor = 0x447558;
	bgColor = 0xF9DA7A;
	fg << colorToString(parseColor(fgColor)).str();
	bg << colorToString(parseColor(bgColor)).str();
	block = true;
}
