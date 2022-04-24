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

char previous = '.';

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
    return false;
     /*return true if the wumpus has been killed or false if the wumpus has not been killed.*/
}