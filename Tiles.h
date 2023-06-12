#pragma once
#include "GameObject.h"

struct tile : GameObject, IBlocking { 
protected:
	bool block = false;
public:
	bool isBlocking() override {
		return block;
	}
};

//From this point, initialized tile children

//Park Tiles
struct grass : tile {
	grass();
};
static const grass tGrass;

struct tallGrass : tile {
private:
	bool animate = false;
public:
	tallGrass();
	std::stringstream getRender() override;
};
static const tallGrass tTallGrass;

struct flower : tile {
	flower();
};
static const flower tFlower;

struct tree : tile {
	tree();
};
static const tree tTree;

struct water : tile {
private: 
	bool animate = false;
public:
	water();
	std::stringstream getRender() override;
};
static const water tWater;

struct bridge : tile {
	bridge();
};
static const bridge tBridge;

//Parking Lot Tiles
struct asphalt : tile {
	asphalt();
};
static const asphalt tAsphalt;

struct parking : tile {
	parking();
};
static const parking tParking;

struct rock : tile {
	rock();
};
static const rock tRock;

struct sand : tile {
	sand();
};
static const sand tSand;

struct cactus : tile {
	cactus();
	void onCollision(GameObject* obj) override;
};
static const cactus tCactus;

//Mall Tiles
struct flooring : tile {
	flooring();
};
static const flooring tFlooring;

struct chair : tile {
	chair();
};
static const chair tChair;

struct table : tile {
	table();
};
static const table tTable;

struct plant : tile {
	plant();
};
static const plant tPlant;

struct wall : tile {
	wall();
};
static const wall tWall;

struct toilet : tile {
	toilet();
};
static const toilet tToilet;

struct clothes : tile {
	clothes();
	void onOverlap(GameObject* obj) override;
};
static const clothes tClothes;

struct food : tile {
	food();
};
static const food tFood;
