/*
 * hazard.cpp
 *
 *      Author: Sai Cherukuru
 */

#include "cell.h"
#include "map.h"
#include "weapon.h"
#include <iostream>
#include "player.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Hazard {
public:
    int xLocation, yLocation;
    char token;
    Map *map;

Hazard(Map *m, int x, int y, char type)
{
    map = m;
    xLocation = x;
    yLocation = y;
    type = token;
}

char getToken();
bool interact();

};

class Pit: public Hazard{
    public:
    char pit = '@';

    char getToken() {
        token = pit;
        return token;
    }
    
    bool interact() {
        token == '@';
        if(map->cells[xLocation][yLocation]->display() == token) {
            cout << "Player fell into the pit and DIED!!!!";
            return true;
        }
        return false;
    }

};

class Bat: public Hazard{
    public:
    char bat = 'B';

    char getToken() {
        token = bat;
        return token;
    }
    
    bool interact() {

        cout << "OH NO! Player got relocated by bats!!";
        char symbols[36] = {'P', '!', 'B', 'B', 'B', '@', '@', '@', '@', '@', 
                            '?', '-', '-', '-', '-', '-', '-', '.', '.', '.', 
                            '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                            '.', '.', '.', '.', '.', '.'};
        int size = 36;
        int index = 0;
        char c = ' ';

        if(map->cells[xLocation][yLocation]->display() == token) {
            for (auto i = 0; i < 6; i++)
                {
                for (auto j = 0; j < 6; j++)
                {
                    index = rand() % size;
                    c = symbols[index];
                    if (c == 'P') {
                        map->playerx = i;
                        map->playery = j;
                    }
                    map->cells[i][j] = new MapCell(i, j, c);
                    for (auto k = index; k < size; k++)
                    {
                        symbols[k] = symbols[k + 1];
                    }
                    size--;
                }
            }
            return true;
        }
        return false;
    }

};
