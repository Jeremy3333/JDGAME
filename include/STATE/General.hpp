#pragma once

#include "STATE/StartMenu.hpp"
#include "STATE/World.hpp"
#include "UTILS/Utils.hpp"

class General
{
private:
    int state;
    Vector2f windowSize;
    StartMenu *startMenu;
    World *world;

public:
    General();
    ~General();

    void setGameState(int state);
    int getGameState();

    Vector2f getWindowSize();

    void openStartMenu();
    StartMenu *getStartMenu();

    void openSettings();

    void openWorld();
    World *getWorld();
};