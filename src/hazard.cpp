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

Hazard(Map *m, int x, int y, char type)
{
    map = m;
    xLocation = x;
    yLocation = y;
    type = token;
}

char getToken();
bool interact();

};

class Pit: public Hazard{
    public:
    char pit = '@';

    char getToken() {
        token = pit;
        return token;
    }
    
    bool interact() {
        token == '@';
        if(map->cells[xLocation][yLocation]->display() == token) {
            cout << "Player fell into the pit and DIED!!!!";
            return true;
        }
        return false;
    }

};

class Bat: public Hazard{
    public:
    char bat = 'B';
    int xRand = rand() % 6;
    int yRand = rand() % 6;
    Player player;

    char getToken() {
        token = bat;
        return token;
    }
    
    bool interact() {
        token == 'B';
        if(map->cells[xLocation][yLocation]->display() == token) {
            cout << "BATS caught the player";
            player.determineMove(xRand, yRand);
            return true;
        }
        return false;
        
    }
};
