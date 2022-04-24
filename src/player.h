/*
 * player.h
 *      Author: Brianna Davis
 */
#ifndef PLAYER_H_
#define PLAYER_H_


class MapCell;
class Map;
#include <string>

class Player{
private:
    int amoCount;
    Map *map;
    int xLocation;
    int yLocation;
public:
    Player(Map *m, int startX, int startY);
    bool move(char direction);
    void shootArrow();
    void checkNeighbors();
};

#endif /*PLAYER_H_*/