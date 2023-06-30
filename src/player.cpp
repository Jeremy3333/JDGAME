#include "Player.hpp"

Player::Player(int P_characterID) : characterID(P_characterID) {}

Player::~Player() {}

Vector2f Player::getPosition()
{
    return position;
}

int Player::getCharacterID()
{
    return characterID;
}