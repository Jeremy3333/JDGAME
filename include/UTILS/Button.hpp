#pragma once

#include <string>

#include "UTILS/Math.hpp"

typedef void (*callback_function)(void);

class Button
{
private:
    Vector2f position;
    Vector2f size;
    std::string text;
    bool textAlignmentCenter;
    int textureID;

public:
    Button(Vector2f position, Vector2f size, std::string text, bool textAlignmentCenter, int textureID);
    ~Button();

    Vector2f getPosition();

    Vector2f getSize();

    std::string getText();

    bool isTextAlignmentCenter();

    int getTextureID();

    bool isMouseOver(Vector2f mousePosition);
};