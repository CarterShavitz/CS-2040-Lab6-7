/*
 * wumpus.h
 *
 *      Author: Sai Cherukuru
 */

#ifndef WUMPUS_H_
#define WUMPUS_H_

class MapCell;
class Map;

class Wumpus {
public:

  int xLocation, yLocation;
  Map *map;
  char token;

  Wumpus(Map *m, int x, int y, char type);

  void killPlayer();
  
  bool isDead();
};

#endif /* WUMPUS_H_ */