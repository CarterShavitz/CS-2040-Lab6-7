#include "player.h"
#include "map.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    Map *map = new Map();
    map->load();
    int playerX = rand () % 6;
    int playerY = rand () % 6;
    Player *player = new Player(map, playerX,playerY);
    map->write();
    bool moved = false;
    while(!moved){
    cout << "Make your move (e/n/w/s): ";
    char direction;
    cin >> direction;
    moved = player->move(direction);
    }
    map->write();

}
