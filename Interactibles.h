#pragma once
#include "Objects.h"

class Collectible : public Object {
public:
	enum CollectibleType {
		NOTSET,
		POINTS,
		KEYS
	};
protected:
	Collectible(int initX, int initY, MapOfObjects* objMap);
	std::string name;
	CollectibleType myType = NOTSET;
public:
	virtual CollectibleType getType() { return myType; }
	void onOverlap(GameObject* obj) override;
};

class ItemKey : public Collectible, public IBlocking {
protected:
	bool block = true;
public:
	ItemKey(int initX, int initY, MapOfObjects* objMap);
	void onCollision(GameObject* obj) override;
	bool isBlocking() override { return block; }
};

class Door : public Object, public IBlocking {
protected:
	bool block;
public:
	Door(int initX, int initY, MapOfObjects* objMap);
	bool isBlocking() override { return block; }
	void onCollision(GameObject* obj) override;
	void unlock();
};