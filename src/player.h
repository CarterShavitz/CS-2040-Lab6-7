/*
 * player.h
 *      Author: Brianna Davis
 */
#ifndef PLAYER_H_
#define PLAYER_H_
#include "map.h"
#include <string>
class Player{
    public:
    int amoCount;
    Map *map;
    int xLocation;
    int yLocation;
    Player(Map *m, int startX, int startY);

    bool move(char direction);
    void shootArrow();
};

#endif /*PLAYER_H_*/