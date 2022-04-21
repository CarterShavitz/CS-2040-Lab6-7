/*
 * player.h
 *      Author: Brianna Davis
 */
#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
class Player{
    public:
    int xLocation;
    int yLocation;
    Player(int startX, int startY);

    void move(char direction);
};

#endif /*PLAYER_H_*/