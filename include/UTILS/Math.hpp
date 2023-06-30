#pragma once

class Vector2f
{
public:
    float x, y;
    Vector2f();
    Vector2f(float x, float y);
    ~Vector2f();
    Vector2f operator+(const Vector2f &other);
    Vector2f operator-(const Vector2f &other);
    Vector2f operator*(const float &other);
    Vector2f operator/(const float &other);
    Vector2f operator+=(const Vector2f &other);
    Vector2f operator-=(const Vector2f &other);
    Vector2f operator*=(const float &other);
    Vector2f operator/=(const float &other);
    bool operator==(const Vector2f &other);
    bool operator!=(const Vector2f &other);
};