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

char prompt(){
    char userIn;
    cout << "Make your move (e/n/w/s) or shoot and arrow (a): " << endl;
    cin >> userIn; 
    if(userIn == 'e' ||userIn == 'n' ||userIn == 's' ||userIn == 'w' ||userIn == 'a'||userIn == 'm'||userIn == 'h'|| userIn == 'd'){
        return userIn;
    } else{
        return ' ';
    }
}

int main()
{
    Map *map = new Map();
    map->load();
    Player *player = new Player(map, map->playerx,map->playery);
    Wumpus *wumpus = new Wumpus(map, map->wumpusx, map->wumpusy);
    map->write();
    
    while(!player->dead && wumpus->alive){
        // while(userIn)
        player->checkNeighbors();
        char userIn = prompt();
        // cout << "Make your move (e/n/w/s) or shoot and arrow (a): " << endl;
        // cin >> userIn;
        // if(userIn != 'a') 
        bool moved = false;
        if (userIn == 'a')
        {
            char shootDirection;
            cout << "Choose direction to shoot(e/n/w/s)" << endl;
            cin >> shootDirection; 
            if(player->shootArrow(shootDirection))
            {
                wumpus->killWumpus();
            }
        }
        
        if (userIn != ' ' && userIn != 'a')
        {
            if(player->move(userIn)) 
            {
                map->write();
            } else {
                
            }
        }
        
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

