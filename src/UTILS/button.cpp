#include "UTILS/Button.hpp"

Button::Button(Vector2f position, Vector2f size, std::string text, bool textAlignmentCenter, int textureID)
    : position(position), size(size), text(text), textAlignmentCenter(textAlignmentCenter), textureID(textureID) {}

Button::~Button() {}

Vector2f Button::getPosition() { return position; }

Vector2f Button::getSize() { return size; }

std::string Button::getText() { return text; }

bool Button::isTextAlignmentCenter() { return textAlignmentCenter; }

int Button::getTextureID() { return textureID; }

bool Button::isMouseOver(Vector2f mousePosition)
{
    return mousePosition.x >= position.x && mousePosition.x <= position.x + size.x && mousePosition.y >= position.y && mousePosition.y <= position.y + size.y;
}