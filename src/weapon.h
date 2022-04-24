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

  Weapon(int x, int y, char type);

  //void shootArrow();
  
  bool hasArrow();
  bool killedWumpus();

};

#endif /* WEAPON_H_ */