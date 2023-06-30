#include "UTILS/Math.hpp"

Vector2f::Vector2f() : x(0), y(0) {}

Vector2f::Vector2f(float x, float y) : x(x), y(y) {}

Vector2f::~Vector2f() {}

Vector2f Vector2f::operator+(const Vector2f &other)
{
    return Vector2f(x + other.x, y + other.y);
}

Vector2f Vector2f::operator-(const Vector2f &other)
{
    return Vector2f(x - other.x, y - other.y);
}

Vector2f Vector2f::operator*(const float &other)
{
    return Vector2f(x * other, y * other);
}

Vector2f Vector2f::operator/(const float &other)
{
    return Vector2f(x / other, y / other);
}

Vector2f Vector2f::operator+=(const Vector2f &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2f Vector2f::operator-=(const Vector2f &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2f Vector2f::operator*=(const float &other)
{
    x *= other;
    y *= other;
    return *this;
}

Vector2f Vector2f::operator/=(const float &other)
{
    x /= other;
    y /= other;
    return *this;
}

bool Vector2f::operator==(const Vector2f &other)
{
    return x == other.x && y == other.y;
}

bool Vector2f::operator!=(const Vector2f &other)
{
    return x != other.x || y != other.y;
}