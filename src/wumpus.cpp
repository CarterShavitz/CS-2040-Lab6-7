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

char previous = '.';

Wumpus::Wumpus(int x, int y, char type)
{
    type == '!';
    token = type;
}

void Wumpus::killPlayer() {

}

bool Wumpus::isDead() {
<<<<<<< HEAD
    return token == '.';
=======
    //return token == '.';
>>>>>>> 9448c9ff92cf4ca6b7db9746924332a06750d409
    /*print out you win line or */
    return false;
    //return token == '.';
    /*print out you win line or this can be done in main*/
}