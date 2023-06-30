#pragma once
#include "Math.hpp"

class Player
{
private:
    Vector2f position;
    int characterID;

public:
    Player(int P_characterID);
    ~Player();

    Vector2f getPosition();

    int getCharacterID();
};