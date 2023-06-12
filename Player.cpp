#include "Player.h"
#include "Input.h"
#include "Interactibles.h"
#include <iostream>


coords setWindowCursorPos(int x, int y);
coords resetWindowCursorPos();

coords Player::inputDirection() {
	inputValues input = getInput();
	return { input.x, input.y };
}
	
Player::Player(int initX, int initY, MapOfObjects* objMap) : Pawn(initX, initY, objMap) {
	symbol = objectSigils::sPLAYER;
	moveSpeed = 4;
	timeToMove = 1000;
	printHP();
	updateKeys();
}
void Player::update(int milisseconds) {
	Pawn::update(milisseconds);
	while (timeElapsed >= (timeToMove / moveSpeed)) {
		move(inputDirection());
		timeElapsed -= timeToMove / moveSpeed;
	}
}

void Player::collect(Collectible* c) {
	switch (c->getType()) {
	case Collectible::POINTS: {points += 0; break; }
	case Collectible::KEYS: {
		keys++; 
		updateKeys();
		//PlaySound(L"Sound/SND_Key.wav", NULL, SND_ASYNC);
		break; }
	}
	c->die();
}
int Player::takeKey() {
	keys--; 
	updateKeys();
	return keys; 
}
void Player::damage(int damage) {
	if (!invincible) {
		hp -= damage;
		printHP();
		if (hp <= 0) {}
		else { invincible = true; }
	}
}
void Player::onCollision(GameObject* obj) {
	if (Pawn* p = dynamic_cast<Pawn*>(obj))
		damage(p->getAtkDamage());
}

void Player::colorize(std::stringstream color) {
	fg.str("");
	fg << color.str();
}

void Player::updateKeys() { //Key Counter
	setWindowCursorPos(0, yWindowOffset + yWindowSize + 3);
	std::cout << static_cast<char>(objectSigils::sKEYS) << " Keys: " << keys;
	resetWindowCursorPos();
}

void Player::printHP() { //HP bar
	float hBarSegmentSize = maxHP / hBarSize;
	float hpPct = (getHP() / maxHP) * 100.0f;
	float hpCur = getHP();
	setWindowCursorPos(xWindowOffset - hBarSize / 2 + xWindowCenter, yWindowOffset + yWindowSize + 6);
	std::cout << "[";
	for (int i = 0; i < hBarSize; i++) {
		std::string outChar;

		float hpSegment = (hpCur - (hBarSegmentSize * i));
		
			 if (hpSegment >= hBarSegmentSize)		  outChar = "0";
		else if (hpSegment >= hBarSegmentSize * 0.5f) outChar = "o";
		else if (hpSegment >  0)					  outChar = ".";
		else outChar = " ";

		std::cout << outChar;
	}
	std::cout << "]";
	resetWindowCursorPos();
}

