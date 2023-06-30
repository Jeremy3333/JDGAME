#pragma once

#include "STATE/StartMenu.hpp"
#include "STATE/World.hpp"
#include "UTILS/Utils.hpp"

class General
{
private:
    StartMenu *startMenu;
    World *world;
    int state;

public:
    General();
    ~General();

    int getGameState();

    void openStartMenu();
    StartMenu *getStartMenu();

    void openSettings();

    void openWorld();
    World *getWorld();
};