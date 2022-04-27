#include "player.h"
#include "map.h"
#include "cell.h"
#include "hazard.cpp"
#include <cstdio>
#include <iostream>

using namespace std;

Player::Player(Map *m, int startX, int startY){
    ammoCount = 4;
    map = m;
    xLocation = startX;
    yLocation = startY;
    dead = false;
}


bool Player::determineMove(int x, int y)
{
  if (map->cells[x][y]->hasWumpus())
  {
    cout << "you've been killed by the wumpus" << endl;
    dead = true;
    return false;
  }
  if (map->cells[x][y]->hasHazard())
  {
      Hazard *hazard = new Hazard(map, x, y, ' ');
      if (map->cells[x][y]->display() == 'B')
      {
          hazard = new Bat(map, x, y, 'B', this);
        //call bat interact
      } else if (map->cells[x][y]->display() == '@') 
      {
          hazard = new Pit(map, x, y, '@');
        //call pit interact
      }
      hazard->interact();
  }
  if (map->cells[x][y]->hasAmmo())
  {
    ammoCount++;
    cout << "you've picked up ammo" << endl;
    map->cells[x][y]->removeAmmo();
  }
  map->cells[x][y]->enter();
  return true;
} 
 
  // move player in specified direction (e/w/s/n), returning true
  //   if was able to move in that direction
bool Player::move(char direction)
{
    direction = tolower(direction);
    if(direction == 'n')
    {
      if(!(yLocation - 1 < 0))
      {
        map->cells[xLocation][yLocation]->vacate();
        yLocation--;
        if(!determineMove(xLocation, yLocation))
        {
          yLocation++;
          map->cells[xLocation][yLocation]->enter();
          return false;
        }
      } else {
        return false;
      }
    } else if(direction == 'e')
    {
      if(!(xLocation + 1 > 5))
      {
        map->cells[xLocation][yLocation]->vacate();
        xLocation++;
        if(!determineMove(xLocation, yLocation))
        {
          xLocation--;
          map->cells[xLocation][yLocation]->enter();
          return false;
        }
      } else {
        return false;
      }
    } else if(direction == 's')
    {
      if(!(yLocation + 1 > 5))
      {
        map->cells[xLocation][yLocation]->vacate();
        yLocation++;
        if(!determineMove(xLocation, yLocation))
        {
          yLocation--;
          map->cells[xLocation][yLocation]->enter();
          return false;
        }
      } else {
        return false;
      }
    } else if(direction == 'w')
    {
      if(!(xLocation - 1 < 0))
      {
        map->cells[xLocation][yLocation]->vacate();
        xLocation--;
        if(!determineMove(xLocation, yLocation))
        {
          xLocation++;
          map->cells[xLocation][yLocation]->enter();
          return false;
        }
      } else {
        return false;
      }
    }

    return true;
}

bool Player::determineShot(int x, int y)
{
    if(ammoCount > 0)
    {
        ammoCount--;
        if (map->cells[x][y]->hasWumpus())
        {
            cout << "you've killed the wumpus!" << endl;
            return true;
        }
        return false;
    } else {
        cout << "you're out of ammo, find ammo" << endl;
        return false;
    }
} 

bool Player::shootArrow(char direction)
{ 
    /*player shoots/clicks right or left or down or up on the arrow*/
    
        /*if checking if there a wumpus there*/
        /*if there a wumpus there, and the arrow is shot the "right" direction, 
        print out the statment the wumpus has been killed*/
        /*shoot the arrow*/
        /*the killed wumpus method might not be 
        needed only because it can be done in this method as well.*/
    direction = tolower(direction);
    int x = xLocation;
    int y = yLocation;
    if(direction == 'n')
    {
      if(!(y - 1 < 0))
      {
        y--;
        if(determineShot(x, y))
        {
            return true;
        }
      } else {
        return false;
      }
    } else if(direction == 'e')
    {
      if(!(x + 1 > 5))
      {
        x++;
        if(determineShot(x, y))
        {
            return true;
        }
      } else {
        return false;
      }
    } else if(direction == 's')
    {
      if(!(y + 1 > 5))
      {
        y++;
        if(determineShot(x, y))
        {
            return true;
        }
      } else {
        return false;
      }
    } else if(direction == 'w')
    {
      if(!(x - 1 < 0))
      {
        x--;
        if(determineShot(x, y))
        {
            return true;
        }
      } else {
        return false;
      }
    }
    return false;
}

void Player::checkNeighbors()
{
    char neighbors[8] = {};
    int size = 0;
    if (xLocation - 1 >= 0)
    {
        if(yLocation - 1 >= 0)
        {
            neighbors[size] = map->cells[xLocation - 1][yLocation - 1]->display();
            size++;
        }
        if (yLocation + 1 <= 5)
        {
            neighbors[size] = map->cells[xLocation - 1][yLocation + 1]->display();
            size++;
        }
        neighbors[size] = map->cells[xLocation - 1][yLocation]->display();
        size++;
    }
    if (xLocation + 1 <= 5)
    {
        if(yLocation - 1 >= 0)
        {
            neighbors[size] = map->cells[xLocation + 1][yLocation - 1]->display();
            size++;
        }
        if (yLocation + 1 <= 5)
        {
            neighbors[size] = map->cells[xLocation + 1][yLocation + 1]->display();
            size++;
        }
        neighbors[size] = map->cells[xLocation + 1][yLocation]->display();
        size++;
    }
    if(yLocation - 1 >= 0)
    {
        neighbors[size] = map->cells[xLocation][yLocation - 1]->display();
        size++;
    }
    if (yLocation + 1 <= 5)
    {
        neighbors[size] = map->cells[xLocation][yLocation + 1]->display();
        size++;
    }

    bool bats = false, wumpus = false, pit = false;
    for (int i = 0; i < size; i++)
    {
        if (neighbors[i] == 'B' && bats == false)
        {
            cout << "You hear flapping. ";
            bats = true;
        } else if (neighbors[i] == '!' && wumpus == false)
        {
            cout << "You smell something bad. ";
            wumpus = true;
        } else if (neighbors[i] == '@' && pit == false)
        {
            cout << "You feel a breeze. ";
            pit = true;
        }
    }
    cout << endl;  
}