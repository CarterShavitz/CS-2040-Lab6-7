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

Weapon::Weapon(int x, int y, char type)
{
    type == '-';
    token = type;
}

bool Weapon::hasArrow() {
    return token == '-';
}

void Weapon::shootArrow()
{
    if(/*player shoots/clicks right or left or down or up on the arrow*/) {
        /*if checking if there a wumpus there*/
        /*if there a wumpus there, and the arrow is shot the "right" direction, 
        print out the statment the wumpus has been killed*/
        /*shoot the arrow*/
        /*the killed wumpus method might not be 
        needed only because it can be done in this method as well.*/
    }
}

bool Weaoon::killedWumpus()
{
     /*return true if the wumpus has been killed or false if the wumpus has not been killed.*/
}