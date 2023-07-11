#include "STATE/StartMenu.hpp"

StartMenu::StartMenu() : startButton(new Button(
                             Vector2f(20, 50), Vector2f(60, 10),
                             "Start", TEXTURE_NONE)),
                         settingsButton(new Button(
                             Vector2f(20, 65), Vector2f(60, 10),
                             "Settings", TEXTURE_NONE)),
                         quitButton(new Button(
                             Vector2f(20, 80), Vector2f(60, 10),
                             "Quit", TEXTURE_NONE))
{
}

StartMenu::~StartMenu()
{
    delete startButton;
    delete settingsButton;
    delete quitButton;
}

Button *StartMenu::getStartButton()
{
    return startButton;
}

Button *StartMenu::getSettingsButton()
{
    return settingsButton;
}

Button *StartMenu::getQuitButton()
{
    return quitButton;
}