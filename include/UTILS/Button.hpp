#pragma once

#include <string>

#include "UTILS/Math.hpp"

typedef void (*callback_function)(void);

class Button
{
private:
    Vector2f position;
    Vector2f size;
    callback_function callback;
    std::string text;
    int textureID;

public:
    Button(Vector2f position, Vector2f size, callback_function callback, std::string text, int textureID);
    ~Button();

    Vector2f getPosition();
    Vector2f getSize();
    void launchCallback();
    std::string getText();
    int getTextureID();
    bool isMouseOver(Vector2f mousePosition);
};