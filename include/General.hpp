#pragma once
#include "World.hpp"
#include "Utils.hpp"

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