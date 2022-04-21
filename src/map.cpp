/*
 * map.cpp
 *
 *      Author: Carter
 */

#include "map.h"
#include "cell.h"
#include "player.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Map::Map()
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            Map::cells[i][j] = new MapCell(i, j, '.');
        }
    }
}

void Map::load()
{
    //randomize loading of elements (1 player, 1 wumpus, 
    //3 bats, 5 hazards, 1 tresure, 6 ammos, 19 empty)
    //Write code here
    srand (time(NULL));

    char symbols[36] = {'P', '!', 'B', 'B', 'B', '@', '@', '@', '@', '@', 
                            '?', '-', '-', '-', '-', '-', '-', '.', '.', '.', 
                            '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                            '.', '.', '.', '.', '.', '.'};
    int size = 36;
    int index = 0;
    char c = ' ';

    for (auto i = 0; i < 6; i++)
    {
        for (auto j = 0; j < 6; j++)
        {
            index = rand() % size;
            c = symbols[index];
            if (c == 'P') {
                playerx = i;
                playery = j;
            }
            Map::cells[i][j] = new MapCell(i, j, c);
            for (auto k = index; k < size; k++)
            {
                symbols[k] = symbols[k + 1];
            }
            size--;
        }
    }
}

void Map::write()
{
    //write the map back with an updated robot location
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
           cout << Map::cells[j][i]->display();
        }
        cout << endl;
    }
}