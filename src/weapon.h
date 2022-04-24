/*
 * weapon.h
 *
 *      Author: Sai Cherukuru
 */

#ifndef WEAPON_H_
#define WEAPON_H_

class Weapon {
 
public:

  int xLocation, yLocation;
  char token;
  MapCell *cell;

  Weapon(MapCell* m, int x, int y, char type);
  bool hasArrow();
  bool killedWumpus();

};

#endif /* WEAPON_H_ */