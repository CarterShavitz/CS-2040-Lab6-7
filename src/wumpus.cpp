/*
 * wumpus.cpp
 *
 *      Author: Sai Cherukuru
 */

#include "cell.h"
#include "map.h"
#include "wumpus.h"
#include <iostream>

using namespace std;

Wumpus::Wumpus(Map *m, int x, int y)
{
    map = m;
    xLocation = x;
    yLocation = y;
    token = '!';
    alive = true;
}

bool Wumpus::isDead() {
    if(!map->cells[xLocation][yLocation]->display() == '!') { //haswumpus() doesn't return a string
        cout << "Nice job, you beat the game!";
        return true;
    }
    return false;
}

void Wumpus::killWumpus() {
    alive = false;
}