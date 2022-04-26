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

/*void Wumpus::killPlayer() {
    char player = 'p';
    //gets the players location
    player = map->cells[xLocation][yLocation]->display(); //Confused what is happening here
    //if the player is at wumpus location and the wumpus is not dead, it kills the player
    if(player == map->cells[xLocation][yLocation]->occupied()) {
        if(!Wumpus.isDead()) {
            cout << "Oh no, the wumpus killed you!";
        }
    }
}
*/
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