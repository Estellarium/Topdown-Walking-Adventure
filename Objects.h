#pragma once
#include "GameObject.h"
#include "Constants.h"
struct tile;


//Core object classes

class Object : public GameObject { //Objects that render over the map
protected:
	char defaultSymbol = ' ';
	bool dead = false;
	int xPos = -1, yPos = -1;
	MapOfObjects* objMap;
	Object(int iXPos, int iYPos, MapOfObjects* objs);
public:
	int getX() { return xPos; }
	int getY() { return yPos; }
	bool isDead() { return dead; }
	void die();
};

class Entity : public Object {
protected:
	int timeElapsed = 0;
	int moveSpeed = 1;
	int timeToMove = 1000;
	Entity(int iXPos, int iYPos, MapOfObjects* objMap);
public:
	virtual void update(int milisseconds);
};

//Specific object classes

class Pawn : public Entity, public IBlocking {
protected:
	bool block = true;
	int maxHP = 20;
	int hp;
	int atkDamage = 5;
	bool invincible = false;
	int iFrames = 1000;
	int curIFrames = iFrames;
public:
	bool isBlocking() { return block; }
	Pawn(int initX, int initY, MapOfObjects* objMap);
	void update(int milisseconds) override;

	int getHP() { return hp; }
	int getMaxHP() { return maxHP; }
	virtual void damage(int damage);
	int getAtkDamage() { return atkDamage; }
	void onCollision(GameObject* obj) override {}
	void onOverlap(GameObject* obj) override {}

	void colorize(std::stringstream color);
	std::stringstream getRender() override;

protected:
	virtual coords inputDirection() { return { 0,0 }; }
	void move(coords to);
	virtual void whenICollide();
};

class Wanderer : public Pawn {
	bool hasMoved = true;
	coords desiredDirection = { 0,0 };
public:
	Wanderer(int initX, int initY, MapOfObjects* objMap);
	void update(int milisseconds) override;
	void onCollision(GameObject* obj) override;
private:
	coords inputDirection() override;
};

class Projectile : public Pawn {
	coords direction = { 0,0 };
	bool block = false;
	int damage = 5;
public:
	Projectile(int initX, int initY, MapOfObjects* objs, coords dir);
	void update(int milisseconds) override;
	void whenICollide() override;
private:
	bool checkNext(int x, int y);
};

class Shooter : public Pawn {
	bool hasMoved = true;
	coords desiredDirection = { 0,0 };
public:
	Shooter(int initX, int initY, MapOfObjects* objMap);
	void update(int milisseconds) override;
private:
	coords inputDirection() override;
};

class Patroller : public Wanderer {
	coords moveDir;
	coords desiredDirection = { 0,0 };
public:
	Patroller(int initX, int initY, MapOfObjects* objMap, coords dir);
	void whenICollide() override;
private:
	coords inputDirection() override { return moveDir; }
};

