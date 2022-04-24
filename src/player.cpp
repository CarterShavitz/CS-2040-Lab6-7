#include "player.h"
#include "map.h"
#include "cell.h"
#include <cstdio>
#include <iostream>

using namespace std;

Player::Player(Map *m, int startX, int startY){
    amoCount = 0;
    map = m;
    xLocation = startX;
    yLocation = startY;
}

bool Player::move(char direction){
    if(direction == 'e'){
        xLocation += 1;
    }
    else if(direction == 'w'){
        xLocation -= 1;
    }
    else if(direction == 'n'){
        yLocation -= 1;
    }
    else if(direction == 's'){
        yLocation += 1;
    } else{
        cout << "enter a valid direction (e/n/w/s)" << endl;
        return false;
    }
    return true;
}

void Player::shootArrow()
{ 
    /*player shoots/clicks right or left or down or up on the arrow*/
    
        /*if checking if there a wumpus there*/
        /*if there a wumpus there, and the arrow is shot the "right" direction, 
        print out the statment the wumpus has been killed*/
        /*shoot the arrow*/
        /*the killed wumpus method might not be 
        needed only because it can be done in this method as well.*/
    
}

void Player::checkNeighbors()
{
    char neighbors[8] = {};
    int size = 0;
    if (xLocation - 1 >= 0)
    {
        if(yLocation - 1 >= 0)
        {
            neighbors[size] = map->cells[xLocation - 1][yLocation - 1]->display();
            size++;
        }
        if (yLocation + 1 <= 5)
        {
            neighbors[size] = map->cells[xLocation - 1][yLocation + 1]->display();
            size++;
        }
        neighbors[size] = map->cells[xLocation - 1][yLocation]->display();
        size++;
    }
    if (xLocation + 1 <= 5)
    {
        if(yLocation - 1 >= 0)
        {
            neighbors[size] = map->cells[xLocation + 1][yLocation - 1]->display();
            size++;
        }
        if (yLocation + 1 <= 5)
        {
            neighbors[size] = map->cells[xLocation + 1][yLocation + 1]->display();
            size++;
        }
        neighbors[size] = map->cells[xLocation + 1][yLocation]->display();
        size++;
    }
    if(yLocation - 1 >= 0)
    {
        neighbors[size] = map->cells[xLocation][yLocation - 1]->display();
        size++;
    }
    if (yLocation + 1 <= 5)
    {
        neighbors[size] = map->cells[xLocation][yLocation + 1]->display();
        size++;
    }

    bool bats = false, wumpus = false, pit = false;
    for (int i = 0; i < size; i++)
    {
        if (neighbors[i] == 'B' && bats == false)
        {
            cout << "You hear flapping. ";
            bats = true;
        } else if (neighbors[i] == '!' && wumpus == false)
        {
            cout << "You smell something bad. ";
            wumpus = true;
        } else if (neighbors[i] == '@' && pit == false)
        {
            cout << "You feel a breeze. ";
            pit = true;
        }
    }
    cout << endl;    
}