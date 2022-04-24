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
    char player = 'p';
    player = cell->display();
    if(player == cell->occupied()) {
        cout << "Oh no, the wumpus killed you!";
    }
}

bool Wumpus::isDead() {
    /*print out you win line or */
    return false;
    //return token == '.';
    /*print out you win line or this can be done in main*/
}