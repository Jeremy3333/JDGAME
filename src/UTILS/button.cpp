#include "UTILS/Button.hpp"

Button::Button(Vector2f position, Vector2f size, callback_function callback, std::string text, int textureID) : position(position), size(size), callback(callback), text(text), textureID(textureID) {}

Button::~Button() {}

Vector2f Button::getPosition() { return position; }

Vector2f Button::getSize() { return size; }

void Button::launchCallback() { callback(); }

std::string Button::getText() { return text; }

int Button::getTextureID() { return textureID; }

bool Button::isMouseOver(Vector2f mousePosition)
{
    return mousePosition.x >= position.x && mousePosition.x <= position.x + size.x && mousePosition.y >= position.y && mousePosition.y <= position.y + size.y;
}