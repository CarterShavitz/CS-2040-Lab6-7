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

Wumpus::Wumpus(Map *m, int x, int y, char type)
{
    map = m;
    xLocation = x;
    yLocation = y;
    type = token;
}

void Wumpus::killPlayer() {
    char player = 'p';
    player = map->cells[xLocation][yLocation]->display(); //Confused what is happening here
    if(player == map->cells[xLocation][yLocation]->occupied()) {
        cout << "Oh no, the wumpus killed you!";
    }
}

bool Wumpus::isDead() {
    if(map->cells[xLocation][yLocation]->hasWumpus() == '.') { //haswumpus() doesn't return a string
        cout << "Nice job, you beat the game!";
        return true;
    }
    return false;
}