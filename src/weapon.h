/*
 * weapon.h
 *
 *      Author: Sai Cherukuru
 */

#ifndef WEAPON_H_
#define WEAPON_H_

class Weapon {
  int xLocation, yLocation;
  char token;
  Map *map;
 
public:

  Weapon(Map *m, int x, int y, char type);
  bool hasArrow();
  bool killedWumpus();

};

#endif /* WEAPON_H_ */