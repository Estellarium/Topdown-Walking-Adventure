#include "GlobalCalls.h"
#include <thread>
#include <iostream>
#include "Constants.h"

using namespace std::chrono;
#define TickClock high_resolution_clock

time_point<TickClock> Global::start = TickClock::now();

void Global::startFrame() {
    start = TickClock::now();
}
void Global::finishFrame() {
    auto end = TickClock::now();
    auto time = duration_cast<milliseconds>(end - start);
    auto waitTime = milliseconds(mps) - time;
    if (waitTime.count() > 0)
        std::this_thread::sleep_for(waitTime);
}
void Global::resizeWindow() {
    std::cout << "\033[?25l"; //Hide Cursor
    std::cout //Set Window Size
        << "\033[8;"
        << (windowHeight + 3) << ";"
        << (windowWidth) << "t";
}