#include "Interactibles.h"
#include "Player.h"

Collectible::Collectible(int initX, int initY, MapOfObjects* objMap) : Object(initX, initY, objMap) {}
void Collectible::onOverlap(GameObject* obj) {
	if (Player* p = dynamic_cast<Player*>(obj)) {
		p->collect(this);
	}
}

ItemKey::ItemKey(int initX, int initY, MapOfObjects* objMap) : Collectible(initX, initY, objMap) {
	symbol = objectSigils::sKEYS;
	myType = KEYS;
}
void ItemKey::onCollision(GameObject* obj) {
	if (Player* p = dynamic_cast<Player*>(obj)) {
		p->collect(this);
	}
}

Door::Door(int initX, int initY, MapOfObjects* objMap) : Object(initX, initY, objMap) {
	symbol = objectSigils::sDOORS;
	bg = colorToString(parseColor(0xCCCCCC));
	block = true;
}
void Door::unlock() {
	block = false;
	die();
}
void Door::onCollision(GameObject* obj) {
	if (Player* p = dynamic_cast<Player*>(obj)) {
		if (p->getKeys() > 0) {
			p->takeKey();
			unlock();
		}
	}
}