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
    cout << "Make your move (e/n/w/s), shoot and arrow (a), debug(d) or get help(h): " << endl;
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
    map->writePlayer(); //comment out once done
    
    while(!player->dead && wumpus->alive){
        player->checkNeighbors();
        char userIn = prompt();
        bool moved = false;
        if (userIn == 'a'){
            char shootDirection;
            cout << "Choose direction to shoot(e/n/w/s)" << endl;
            cin >> shootDirection; 
            if(player->shootArrow(shootDirection))
            {
                wumpus->killWumpus();
            } else
            {
                cout << "You Missed!" << endl;
            }
            map->writePlayer();
        }
        else if (userIn != ' '){
            if((userIn != 'h' && userIn != 'd') && userIn != 'm'){
            player->move(userIn);
            if(!player->dead) {
                map->writePlayer();
            } //comment out once done
            } else if(userIn == 'd'){
                //debug mode (print out default map, restarting game)
                //maybe create another method to call in here
                map->debugLoad();
                player = new Player(map, map->playerx,map->playery);
                wumpus = new Wumpus(map, map->wumpusx, map->wumpusy);
                map->write();
            } else if(userIn == 'h'){
                //help mode (print out how the game works or something along those lines)
                cout << "Goal: kill the wumpus before something else kills you" << endl;
                cout << "Use your senses to navigate the cave" << endl;
                cout << "Avoid hazards like falling in pits, and being carried away by bats" << endl;
                cout << "Find arrows on the map to kill the wumpus" << endl;
                cout << "Best of luck!" << endl;
            } else if(userIn == 'm'){
                map->write();
            }
        }
        else{
            cout << "invalid selection" << endl;
        }
    }
    if(player->dead){
        cout << "Better luck next time" << endl;
    } else{
        cout << "Congratulations!" << endl;
    }
    return 0;
}

