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

Weapon::Weapon(MapCell *m, int x, int y, char type)
{
    cell = m;
    xLocation = x;
    yLocation = y;
    type = token;
}

bool Weapon::hasArrow() {
    return token == '-';
}

bool Weapon::killedWumpus()
{
    if(cell->hasWumpus() == '.') {
        return true;
    }
    return false;
}