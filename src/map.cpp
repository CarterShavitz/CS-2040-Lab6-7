/*
 * map.cpp
 *
 *      Author: Carter
 */

#include "map.h"
#include "cell.h"
#include "robot.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Map::Map()
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            Map::cells[i][j] = nullptr;
        }
    }
}

void Map::load()
{
    //randomize loading of elements (1 player, 1 wumpus, 
    //3 bats, 5 hazards, 1 tresure, 6 ammos, 19 empty)
    //Write code here
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