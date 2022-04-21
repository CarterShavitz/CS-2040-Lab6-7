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