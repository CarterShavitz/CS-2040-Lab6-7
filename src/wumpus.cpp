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
    return token == '.';
    /*print out you win line or */
}