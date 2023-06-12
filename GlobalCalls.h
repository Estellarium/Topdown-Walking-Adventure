#pragma once
#include <chrono>
using namespace std::chrono;
#define TickClock high_resolution_clock

static const class Global {
    static time_point<TickClock> start;
public:
    static void startFrame();
    static void finishFrame();
    static void resizeWindow();
    static void setConsole();
};