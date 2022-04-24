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

Wumpus::Wumpus(Map *m, int x, int y, char type)
{
    xLocation = x;
    yLocation = y;
    type == '!';
    token = type;
}

void Wumpus::killPlayer() {

}

bool Wumpus::isDead() {
<<<<<<< HEAD
=======
    //return token == '.';
>>>>>>> a26518af45014d4d9935021d56fab5055d06dd4f
    /*print out you win line or */
    return false;
    //return token == '.';
    /*print out you win line or this can be done in main*/
}