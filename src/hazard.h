/*
 * player.h
 *      Author: Sai Cherukuru
 */
#ifndef HAZARD_H_
#define HAZARD_H_

using namespace std;

class Hazard{
public:

  int xLocation, yLocation;
  char token;
  Map *map;

  Hazard(Map* m, int x, int y, char type);
  //bool hasArrow();
};

#endif /*PLAYER_H_*/