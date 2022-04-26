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
  bool alive;

  Wumpus(Map *m, int x, int y);

  void killPlayer();

  void killWumpus();
  
  bool isDead();
};

#endif /* WUMPUS_H_ */