#pragma once
#include "Constants.h"

static char tlC = 201; //Top Lft Crnr - ╔
static char trC = 187; //Top Rgt Crnr - ╗
static char blC = 200; //Btm Lft Crnr - ╚
static char brC = 188; //Btm Rgt Crnr - ╝
static char hLn = 205; //Horizntl Bar - ═
static char vLn = 186; //Vertical Bar - ║
static char tJn = 203; //Junction Top - ╦
static char bJn = 202; //Junction Btm - ╩
static char lJn = 204; //Junction Lft - ╠
static char rJn = 185; //Junction Rgt - ╣
static char crs = 206; //Marker Cross - ╬

//Comandos de cursor do windows CMD, peguei da internet
coords setWindowCursorPos(int x, int y);
coords resetWindowCursorPos();

//Print box around the window
void printGameWindow(int xWindowOffset, int xWindowEnd, int yWindowOffset, int yWindowEnd);