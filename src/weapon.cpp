/*
 * cell.cpp
 *
 *      Author: Sai Cherukuru
 */

#include "cell.h"
#include "map.h"
#include "weapon.h"
#include <iostream>

using namespace std;

Weapon::Weapon(Map *m, int x, int y, char type)
{
    map = m;
    xLocation = x;
    yLocation = y;
    type = token;
}

bool Weapon::hasArrow() {
    return token == '-';
}

bool Weapon::killedWumpus()
{
    token == '.';
    if(map->cells[xLocation][yLocation]->hasWumpus() == token) {
        return true;
    }
    return false;
}