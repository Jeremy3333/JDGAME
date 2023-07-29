#pragma once

#include <SDL2/SDL.h>

#include "../UTILS/Utils.hpp"

class Event
{
private:
    int keys[KEYS_COUNT];
    bool isKey[KEYS_COUNT];
    bool isRepeat[KEYS_COUNT];
    bool quit;
    SDL_Event event;

public:
    Event();
    ~Event();

    void update();

    bool isKeyPressed(int key);

    bool isKeyRepeat(int key);
    void setKeyRepeat(int key, bool value);

    void setKey(int key, bool value);

    bool isQuit();
    void setQuit(bool value);

    void setToDefault();
};