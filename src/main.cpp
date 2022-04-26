/**
 * @file main.cpp
 * @author Brianna Davis
 * @brief  game driver class
 *  
 */
#include "player.h"
#include "map.h"
#include "wumpus.h"
#include "cell.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    Map *map = new Map();
    map->load();
    Player *player = new Player(map, map->playerx,map->playery);
    // Wumpus *wumpus = new Wumpus()
    map->write();
    // while(map.)
    bool moved = false;
    char direction;
    while(!moved)
    {
        player->checkNeighbors();
        cout << "Make your move (e/n/w/s): ";
        cin >> direction;
        if(player->move(direction)) 
        {
            map->write();
        } else {
            map->write();
        }
    }
    map->write();
}
