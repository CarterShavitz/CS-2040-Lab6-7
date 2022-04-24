/*
 * cell.cpp
 *
 *      Author: Carter
 */

#include "cell.h"
#include "map.h"
#include "wumpus.h"
#include <iostream>

using namespace std;

char previous = '.';

MapCell::MapCell(int x, int y, char type)
{
    token = type;
}

bool MapCell::hasWumpus()
{
    return token == '!';
}
  // true if bat at this location
bool MapCell::hasBat()
{
    return token == 'B';
}
  // true if hazard at this location
bool MapCell::hasHazard()
{
    return token == '@';
}
  // true if bat at this location
bool MapCell::hasTreasure()
{
    return token == '?';
}
  // true if hazard at this location
bool MapCell::hasAmmo()
{
    return token == '-';
}
  // remove the ammo at this location
void MapCell::removeAmmo()
{
  token = '.';
}

  // is this location occupied by the wumpus
bool MapCell::occupied()
{
  return hasWumpus();
}
  // return the character to display for this location
char MapCell::display()
{
  return token;
}
  // player enters location
void MapCell::enter()
{
  previous = token;
  token = 'P';  
}
  // player leaves location
void MapCell::vacate()
{
  if (previous == '-')
  {
    previous = '.';
  }
  if (previous == 'P')
  {
    previous = '.';
  }

  token = previous;
}