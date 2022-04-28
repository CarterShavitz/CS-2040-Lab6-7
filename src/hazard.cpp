/*
 * hazard.cpp
 *
 *      Author: Sai Cherukuru
 */

#include "cell.h"
#include "map.h"
#include "weapon.h"
#include <iostream>
#include "player.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Hazard {
public:
    int xLocation, yLocation;
    char token;
    Map *map;

    Hazard()
    {

    }

    Hazard(Map *m, int x, int y, char type)
    {
        map = m;
        xLocation = x;
        yLocation = y;
        type = token;
    }

    char getToken() {
        cout << "shouldn't print" << endl;
        return ' ';
    }
    virtual bool interact() {
        cout << "shouldn't print" << endl;
        return false;
    }
};

class Pit: public Hazard{
    public:
    char pit = '@';
    Player *player = new Player(map, xLocation, yLocation);

    Pit(Map *m, int x, int y, char type, Player *player)
    {
        this->player = player;
    }

    char getToken() {
        token = pit;
        return token;
    }
    
    bool interact() {
        token == '@';
        cout << "Player fell into the pit and DIED!!!!" << endl;
        player->dead = true;
        return false;
    }

};

class Bat: public Hazard{
    public:
    char bat = 'B';
    int xRand = rand() % 6;
    int yRand = rand() % 6;
    Player *player = new Player(map, xLocation, yLocation);

    Bat(Map *m, int x, int y, char type, Player *player)
    {
        map = m;
        this->player = player;
    }

    char getToken() {
        token = bat;
        return token;
    }
    
    bool interact() {
        cout << "BATS caught the player" << endl;
        map->cells[player->getX()][player->getY()]->vacate();
        map->cells[player->getX()][player->getY()]->setCell('B');
        player->setX(xRand);
        player->setY(yRand);
        return player->determineMove(xRand, yRand);
    }
};
