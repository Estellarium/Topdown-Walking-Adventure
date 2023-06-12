#include "WindowPrinter.h"
#include <iostream>

coords setWindowCursorPos(int x, int y) {
    coords coord;
    coord.x = x * (1 + (padding * 2));
    coord.y = y;
    std::cout << "\033[" << coord.y << ";" << coord.x << "H";
    return coord;
}

coords resetWindowCursorPos() {
    return setWindowCursorPos(xWindowOffset + xWindowCenter, yWindowOffset + yWindowCenter);
}

//Print box around the window
void printGameWindow(int xWindowOffset, int xWindowEnd, int yWindowOffset, int yWindowEnd) {
    for (int x = xWindowOffset; x <= xWindowOffset + xWindowEnd + 1; x++) {
        for (int y = yWindowOffset; y <= yWindowOffset + yWindowEnd + 1; y++) {
            setWindowCursorPos(x, y);
            if (x == xWindowOffset) {
                if (y == yWindowOffset)
                    std::cout << tlC;
                else if (y == yWindowOffset + yWindowEnd + 1)
                    std::cout << blC;
                else
                    std::cout << vLn;
            }
            else if (x == xWindowOffset + xWindowEnd + 1) {
                if (y == yWindowOffset)
                    std::cout << trC;
                else if (y == yWindowOffset + yWindowEnd + 1)
                    std::cout << brC;
                else
                    std::cout << vLn;
            }
            else if (y == yWindowOffset)
                std::cout << hLn;
            else if (y == yWindowOffset + yWindowEnd + 1)
                std::cout << hLn;
            else
                std::cout << " ";
        }
    }
}