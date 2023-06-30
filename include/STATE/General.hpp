#pragma once

#include "STATE/World.hpp"
#include "UTILS/Utils.hpp"

class General
{
private:
    World *world;
    int state;

public:
    General();
    ~General();

    World *getWorld();
    int getGameState();

    void openStartMenu();

    void openSettings();
};