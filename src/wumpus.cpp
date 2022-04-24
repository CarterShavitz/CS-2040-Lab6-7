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

Wumpus::Wumpus(MapCell *m, int x, int y, char type)
{
    cell = m; 
    xLocation = x;
    yLocation = y;
    type = token;
}

void Wumpus::killPlayer() {
    if(cell->enter() == cell->hasWumpus()) {
        cout << "Oh no, the wumpus killed you!";
        token = '.';
    }
}

bool Wumpus::isDead() {
    //return token == '.';
    /*print out you win line or */
    return false;
    //return token == '.';
    /*print out you win line or this can be done in main*/
}