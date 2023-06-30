#pragma once
#include "Player.hpp"

class World
{
private:
    Player *player;

public:
    World(int P_characterID);
    ~World();

    Player *getPlayer();
};
