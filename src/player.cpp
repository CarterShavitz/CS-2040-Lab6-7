#include "player.h"
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