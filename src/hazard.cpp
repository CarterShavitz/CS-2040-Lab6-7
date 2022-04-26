/*
 * hazard.cpp
 *
 *      Author: Sai Cherukuru
 */

#include "cell.h"
#include "map.h"
#include "weapon.h"
#include <iostream>

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
bool killed();
};

class Hole: public Hazard{
    public:
    char hole = '@';

    char getToken() {
        token = hole;
        return token;
    }
    
    bool killed() {
        token == '@';
        if(map->cells[xLocation][yLocation]->getToken() == token) {
            cout << "Player fell into the hole and DIED!!!!";
            return true;
        }
        return false;
    }

};

class Spike: public Hazard{
    public:
    char spike = '&';

    char getToken() {
        token = spike;
        return token;
    }
    
    bool killed() {
        token == '&';
        if(map->cells[xLocation][yLocation]->getToken() == token) {
            cout << "Player got killed by SPIKES!!!";
            return true;
        }
        return false;
    }

};
