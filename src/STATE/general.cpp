#include "STATE/General.hpp"

General::General() : state(STATE_START_MENU), windowSize(Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)), startMenu(new StartMenu()), world(nullptr) {}

General::~General()
{
    if (world != nullptr)
        delete world;
}

void General::setGameState(int state)
{
    this->state = state;
}

int General::getGameState()
{
    return state;
}

Vector2f General::getWindowSize()
{
    return windowSize;
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