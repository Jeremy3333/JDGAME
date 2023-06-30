#pragma once

#include <iostream>

#include "UTILS/Button.hpp"
#include "UTILS/Utils.hpp"

class StartMenu
{
private:
    Button *startButton;
    Button *settingsButton;
    Button *quitButton;

public:
    StartMenu();
    ~StartMenu();

    Button *getStartButton();
    Button *getSettingsButton();
    Button *getQuitButton();
};