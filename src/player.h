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
    int ammoCount;
    Map *map;
    int xLocation;
    int yLocation;
public:
    bool dead;
    Player(Map *m, int startX, int startY);
    bool move(char direction);
    bool shootArrow(char direction);
    bool determineShot(int x, int y);
    void checkNeighbors();
    bool determineMove(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
};

#endif /*PLAYER_H_*/