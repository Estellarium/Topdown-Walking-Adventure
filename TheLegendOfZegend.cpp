#include <string>
#include <iostream>
#include <Windows.h>
#include "GlobalCalls.h"
#include "WindowPrinter.h"
#include "Map.h"
#include "Interactibles.h"
#include "Player.h"
#include "Input.h"
#include "Menus.h"

MapOfObjects objectMap;

bool menu = true;

void play();

int main()
{
    Global::resizeWindow();

    for (int i = 0; i < (sizeof(MainMenu) / sizeof(MainMenu[0])); i++) {
        setWindowCursorPos(0, i + 1);
        std::cout << MainMenu[i];
    }

    int alternate = 0;
    while (menu) {
        Global::resizeWindow();
        inputValues input = getInput();
        if (input.start) alternate = -1;
        if (alternate > -1) {
            Global::startFrame();

            if (alternate % fps > (fps / 2 - 1)) {
                setWindowCursorPos(7, windowHeight);
                std::cout << "\033[0mPRESS SPACE TO PLAY";
            }
            else {
                setWindowCursorPos(0, windowHeight);
                std::cout << MainMenu[windowHeight];
            }
            alternate = (alternate + 1) % fps;
            setWindowCursorPos(0, 0);

            Global::finishFrame();
        }
        else {
            PlaySound(L"Sound/SND_Key.wav", NULL, SND_ASYNC);
            while (alternate > -fps) {
                setWindowCursorPos(7, windowHeight);
                std::cout << "\033[0mPRESS SPACE TO PLAY";
                Global::startFrame();
                alternate--;
                Global::finishFrame();
                setWindowCursorPos(0, windowHeight);
                std::cout << MainMenu[windowHeight];
            }
            menu = false;
            break;
        }
    }
    for (int y = 0; y < windowHeight + 4; y++)
        for (int x = 0; x < windowWidth + 1; x++) {
            setWindowCursorPos(x, y); std::cout << " ";
        }
    printGameWindow(xWindowOffset, xWindowSize, yWindowOffset, yWindowSize);  //Print contours etc of the game screen
    play();
}

bool running = true;
bool paused = false;
bool playerDead = false;
bool deathJingle = false;
std::string pauseText = "PAUSED";

void initialize();

void play() {

    initialize();

    int xPos = 4, yPos = 2;                                                   //Player starting Position
    Player* p = new Player(xPos, yPos, &objectMap);

    ///////////////////////////////////////////////////////////////////////Boot game window
    PlaySound(L"Sound/BGM.wav", NULL, SND_ASYNC | SND_LOOP);

    xWindowStart = p->getX() - xWindowCenter; 
    xWindowEnd = p->getX() + xWindowCenter + 1; //Initial set of the window location

    yWindowStart = p->getY() - yWindowCenter; 
    yWindowEnd = p->getY() + yWindowCenter + 1;
    ///////////////////////////////////////////////////////////////////////

    while (running) {
        /////////////////////////////////////////////Verify input and breakstates on the pause/death screen
        inputValues curInput = getInput();
        paused = curInput.pause;
        if (curInput.close) break;
        if (curInput.restart) {
            play();
        }

        while (!paused || !playerDead) {
            std::cout << "\033[?25l";   //Hide Cursor

            /////////////////////////////////////////Verify input and breakstates during gameplay
            inputValues curInput = getInput();
            paused = curInput.pause;
            if (curInput.pause) break;
            if (curInput.close) break;

            if (p->getHP() <= 0) {
                pauseText = "GAME OVER";
                playerDead = true;
                break;
            }
            /////////////////////////////////////////

            Global::resizeWindow();
            Global::startFrame();

            //////////////////////////////////////////////////////////Update Entities
            MapOfObjects::iterator it; 
            for (it = objectMap.begin(); it != objectMap.end();) {
                Object* o = it->second;
                if (o == nullptr) {
                    it = objectMap.erase(it);
                }
                else
                    if (o->isDead() == true) {
                        it = objectMap.erase(it);
                        delete o;
                    }
                    else {
                        Entity* e = dynamic_cast<Entity*>(o);
                        if (e) e->update(mps);
                        it++;
                    }
            }
            ///////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////Update Screen
            std::vector<std::string> screen;
            screen.reserve(yWindowSize);

            for (int y = yWindowStart; y < yWindowEnd; y++) {
                std::string row;
                row.reserve(xWindowSize);

                for (int x = xWindowStart; x < xWindowEnd; x++) {
                    auto it = objectMap.find({ x,y });
                    if (it != objectMap.end()) {
                        Object* obj = it->second;
                        if (obj) row += obj->getRender().str();
                        else goto getTile;
                    }
                    else {
                    getTile:
                        row += MapC(x, y)->getRender().str();
                    }
                }
                screen.push_back(row);
            }
            for (int i = 0; i < yWindowSize; i++) {
                setWindowCursorPos(xWindowOffset + 1, yWindowOffset + 1 + i);
                std::cout << screen[i] << std::endl;
            }
            ////////////////////////////////////////////////////////////

            std::cout << flush;

            xWindowStart = p->getX() - xWindowCenter; xWindowEnd = p->getX() + xWindowCenter + 1; //Update window location on player location
            yWindowStart = p->getY() - yWindowCenter; yWindowEnd = p->getY() + yWindowCenter + 1;

            //Reset cursor, check elapsed time and wait for next frame
            setWindowCursorPos(0, 0);
            Global::finishFrame();
        }
        setWindowCursorPos(xWindowOffset - pauseText.length() / 2 + xWindowCenter + 1, yWindowCenter + yWindowOffset + 1);
        std::cout << flush << pauseText;
        if (playerDead && !deathJingle) {
            PlaySound(L"Sound/SND_Death.wav", NULL, SND_SYNC);
            deathJingle = true;
        }
    }
    setWindowCursorPos(0, yWindowOffset + yWindowSize + 10);
}

void initialize() {

    //Initialize
    initializeMap();
    objectMap.clear();
    paused = false;
    playerDead = false;
    deathJingle = false;
    pauseText = "PAUSED";

    //Initialize objects
    //Static Objects
    ItemKey* key1 = new ItemKey(11, 14, &objectMap);
    ItemKey* key2 = new ItemKey(13, 38, &objectMap);
    ItemKey* key3 = new ItemKey(11, 29, &objectMap);
    Door* door1 = new Door(18, 5, &objectMap);
    Door* door2 = new Door(17, 29, &objectMap);
    Door* door3 = new Door(17, 31, &objectMap);

    //Dynamic Objects
    Wanderer* w1 = new Wanderer(13, 4, &objectMap);
    Wanderer* w2 = new Wanderer(33, 8, &objectMap);
    Wanderer* w3 = new Wanderer(35, 5, &objectMap);
    Wanderer* w4 = new Wanderer(31, 22, &objectMap);
    Wanderer* w5 = new Wanderer(4, 31, &objectMap);
    Wanderer* w6 = new Wanderer(4, 24, &objectMap);

    Patroller* p1 = new Patroller(20, 22, &objectMap, { 0,  1 });
    Patroller* p2 = new Patroller(37, 16, &objectMap, { 0, -1 });
    Patroller* p3 = new Patroller(28, 21, &objectMap, { -1,  0 });
    Patroller* p4 = new Patroller(4, 35, &objectMap, { -1,  0 });
    Patroller* p5 = new Patroller(9, 34, &objectMap, { 1,  0 });
    Patroller* p6 = new Patroller(14, 35, &objectMap, { -1,  0 });

    Shooter* s1 = new Shooter(9, 13, &objectMap);
    Shooter* s2 = new Shooter(26, 8, &objectMap);
    Shooter* s3 = new Shooter(30, 15, &objectMap);

}