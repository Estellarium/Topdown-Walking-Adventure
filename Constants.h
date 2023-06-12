#pragma once
#if !defined(CONSTANTS_H)
#define CONSTANTS_H

#define MapOfObjects std::unordered_map<coords, Object*, coords::hash>

#include <unordered_map>

enum objectSigils {
    sPLAYER = '@',
    sPOINTS = '*',
    sKEYS = 'q',
    sDOORS = '#',
    sWANDER = 'o',
    sSHOOT = 147,//ô
    sPATROL = 148,//ö
    sSHOT = '.'
};

struct coords {
    int x; int y;

    bool operator==(const coords& other) const {
        return x == other.x && y == other.y;
    }

    struct hash {
        size_t operator()(const coords& c) const {
            return std::hash<int>()(c.x) ^ std::hash<int>()(c.y);
        }
    };
};

static const std::string flush = "\033[38;2;0;48;2;0m";

static const int padding = 0;
static const int xWindowSize = 17, yWindowSize = 9;           //Window X,Y scale (X scale is double that of Y to make it square)
static const int xWindowCenter = (xWindowSize / 2);           //Window Center
static const int yWindowCenter = (yWindowSize / 2);
static const int xWindowOffset = 7, yWindowOffset = 4;        //Window offset from top left corner (keep at 8,4)
static int xWindowStart = 0, xWindowEnd = xWindowSize;        //Window Size
static int yWindowStart = 0, yWindowEnd = yWindowSize;
static const int hBarSize = 10;                               //HP bar size on-screen

static const int windowWidth = xWindowSize + (xWindowOffset * 2);
static const int windowHeight = yWindowSize + (yWindowOffset * 2);

static const int fps = 30;
static const int mps = fps * 100 / 60;

#endif // !CONSTANTS_H
