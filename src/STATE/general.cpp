#include "STATE/General.hpp"

General::General() : startMenu(new StartMenu()), world(nullptr), state(STATE_START_MENU) {}

General::~General()
{
    if (world != nullptr)
        delete world;
}

int General::getGameState()
{
    return state;
}

void General::openStartMenu()
{
    state = STATE_START_MENU;
}

StartMenu *General::getStartMenu()
{
    return startMenu;
}

void General::openSettings()
{
    state = STATE_SETTINGS;
}

World *General::getWorld()
{
    return world;
}