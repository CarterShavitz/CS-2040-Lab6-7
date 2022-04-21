#include "player.h"
#include "map.h"
#include "wumpus.h"
#include "cell.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    Map *map = new Map();
    map->load();
    Player *player = new Player(map, map->playerx,map->playery);
    map->write();
    // while(player->xLocation != )
    bool moved = false;
    while(!moved){
    cout << "Make your move (e/n/w/s): ";
    char direction;
    cin >> direction;
    moved = player->move(direction);
    }
    map->write();

}
