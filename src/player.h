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
    bool dead;
    Player(Map *m, int startX, int startY);
    bool move(char direction);
    void shootArrow(char direction);
    void checkNeighbors();
    bool determineMove(int x, int y);
};

#endif /*PLAYER_H_*/