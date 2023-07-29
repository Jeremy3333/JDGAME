#include "SDL/Event.hpp"

Event::Event()
{
    setToDefault();
    quit = false;
}

Event::~Event()
{
}

void Event::update()
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == keys[KEY_UP])
            {
                if (isKey[KEY_UP])
                    isRepeat[KEY_UP] = true;
                else
                    isKey[KEY_UP] = true;
            }
            else if (event.key.keysym.sym == keys[KEY_DOWN])
            {
                if (isKey[KEY_DOWN])
                    isRepeat[KEY_DOWN] = true;
                else
                    isKey[KEY_DOWN] = true;
            }
            else if (event.key.keysym.sym == keys[KEY_LEFT])
            {
                if (isKey[KEY_LEFT])
                    isRepeat[KEY_LEFT] = true;
                else
                    isKey[KEY_LEFT] = true;
            }
            else if (event.key.keysym.sym == keys[KEY_RIGHT])
            {
                if (isKey[KEY_RIGHT])
                    isRepeat[KEY_RIGHT] = true;
                else
                    isKey[KEY_RIGHT] = true;
            }
            else if (event.key.keysym.sym == keys[KEY_CANCEL])
            {
                if (isKey[KEY_CANCEL])
                    isRepeat[KEY_CANCEL] = true;
                else
                    isKey[KEY_CANCEL] = true;
            }
        }
        else if (event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == keys[KEY_UP])
            {
                isKey[KEY_UP] = false;
                isRepeat[KEY_UP] = false;
            }
            else if (event.key.keysym.sym == keys[KEY_DOWN])
            {
                isKey[KEY_DOWN] = false;
                isRepeat[KEY_DOWN] = false;
            }
            else if (event.key.keysym.sym == keys[KEY_LEFT])
            {
                isKey[KEY_LEFT] = false;
                isRepeat[KEY_LEFT] = false;
            }
            else if (event.key.keysym.sym == keys[KEY_RIGHT])
            {
                isKey[KEY_RIGHT] = false;
                isRepeat[KEY_RIGHT] = false;
            }
            else if (event.key.keysym.sym == keys[KEY_CANCEL])
            {
                isKey[KEY_CANCEL] = false;
                isRepeat[KEY_CANCEL] = false;
            }
        }
        else if (event.type == SDL_QUIT)
        {
            quit = true;
        }
    }
}

bool Event::isKeyPressed(int key)
{
    return isKey[key];
}

bool Event::isKeyRepeat(int key)
{
    return isRepeat[key];
}

void Event::setKeyRepeat(int key, bool value)
{
    isRepeat[key] = value;
}

void Event::setKey(int key, bool value)
{
    isKey[key] = value;
}

bool Event::isQuit()
{
    return quit;
}

void Event::setQuit(bool value)
{
    quit = value;
}

void Event::setToDefault()
{
    keys[KEY_UP] = DEFAULT_KEY_UP;
    keys[KEY_DOWN] = DEFAULT_KEY_DOWN;
    keys[KEY_LEFT] = DEFAULT_KEY_LEFT;
    keys[KEY_RIGHT] = DEFAULT_KEY_RIGHT;
    keys[KEY_CANCEL] = DEFAULT_KEY_CANCEL;
    for (int i = 0; i < KEYS_COUNT; i++)
    {
        isKey[i] = false;
    }
    for (int i = 0; i < KEYS_COUNT; i++)
    {
        isRepeat[i] = false;
    }
}
