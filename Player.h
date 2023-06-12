#pragma once
#include "Objects.h"
class Collectible;

class Player : public Pawn {
	int keys = 0;
	int points = 0;
	void updateKeys();
	void printHP();
protected:
	int maxHP = 20;
	coords inputDirection() override;
	
public:
	Player(int initX, int initY, MapOfObjects* objMap);
	void update(int milisseconds) override;

	void collect(Collectible* c);
	int getKeys() { return keys; }
	int takeKey();
	void damage(int damage) override;
	void onCollision(GameObject* obj) override;
	void onOverlap(GameObject* obj) override {}
	void colorize(std::stringstream color);
};