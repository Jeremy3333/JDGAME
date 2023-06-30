#include "STATE/World.hpp"

World::World(int P_characterID) : player(new Player(P_characterID)) {}

World::~World()
{
    if (player != nullptr)
        delete player;
}

Player *World::getPlayer()
{
    return player;
}