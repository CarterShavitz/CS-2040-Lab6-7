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
    map->write();
    
    while(!player->dead){
        // while(userIn)
        char userIn = prompt();
        // cout << "Make your move (e/n/w/s) or shoot and arrow (a): " << endl;
        // cin >> userIn;
        // if(userIn != 'a') 
        bool moved = false;
        // while(!moved)
        // {
        //     player->checkNeighbors();
        //     cout << "Make your move (e/n/w/s): ";
        //     char direction; 
        //     cin >> direction;
        //     if(player->move(direction)) 
        //     {
        //         map->write();
        //     } else {
        //         map->write();
        //     }
        // }
        // map->write();
    }
}
char prompt(){
    char userIn;
    cout << "Make your move (e/n/w/s) or shoot and arrow (a): " << endl;
    cin >> userIn; 
    if(userIn == 'e' ||userIn == 'n' ||userIn == 's' ||userIn == 'w' ||userIn == 'a'){
        return userIn;
    } else{

    }
}
