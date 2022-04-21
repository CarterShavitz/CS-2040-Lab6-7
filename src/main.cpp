#include "player.h"
#include "map.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    Map *map = new Map();
    map->load();
    Player *player = new Player(map, 0,0);
    map->write();
    bool moved = false;
    while(!moved){
    cout << "Make your move (e/n/w/s): ";
    char direction;
    cin >> direction;
    moved = player->move(direction);
    }

}
