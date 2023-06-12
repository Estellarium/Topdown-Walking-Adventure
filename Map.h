#pragma once
#include "Tiles.h"

static const int mapX = 40, mapY = 40;
static tile* map[mapX][mapY];

extern int clamper(int val, int min, int max);
extern tile* MapC(int x, int y);
extern void initializeMap();

extern const tile* actualmap[mapX][mapY];

//Park Tiles
static const tile* gr = &tGrass;
static const tile* tg = &tTallGrass;
static const tile* fw = &tFlower;
static const tile* tr = &tTree;
static const tile* wa = &tWater;
static const tile* br = &tBridge;

// Parking Lot Tiles
static const tile* as = &tAsphalt;
static const tile* pa = &tParking;
static const tile* ro = &tRock;
static const tile* sa = &tSand;
static const tile* ca = &tCactus;

// Mall Tiles
static const tile* fl = &tFlooring;
static const tile* ch = &tChair;
static const tile* ta = &tTable;
static const tile* pl = &tPlant;
static const tile* wl = &tWall;
static const tile* to = &tToilet;
static const tile* cl = &tClothes;
static const tile* fo = &tFood;

