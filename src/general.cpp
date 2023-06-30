#include "General.hpp"

General::General() : world(nullptr), state(STATE_START_MENU) {}

General::~General()
{
    if (world != nullptr)
        delete world;
}

World *General::getWorld()
{
    return world;
}

int General::getGameState()
{
    return state;
}

void General::openStartMenu()
{
    state = STATE_START_MENU;
}

void General::openSettings()
{
    state = STATE_SETTINGS;
}