/*
 * cell.h
 *
 *      Author: Carter
 */

#ifndef CELL_H_
#define CELL_H_

// Tracks the contents of a particular cell on the map.
// Is there bats at this location, is it occupied by the player,
// is there the wumpus there? Each cell needs to track
// where it is on the grid (x, y) and the type of
// object at that location. The provided methods are suggestions;
// feel free to add/remove as needed.
class MapCell {
  int xLocation, yLocation;
  char token;
  bool hasRobot;
public:
  MapCell(int x, int y, char type);
  // true if wumpus at this location
  bool hasWumpus();
  // true if bat at this location
  bool hasBat();
  // true if hazard at this location
  bool hasHazard();
  // true if treasure at this location
  bool hasTreasure();
  // remove the ammo at this location
  void removeAmmo();
  // is this location occupied by the wumpus
  bool occupied();
  // return the character to display for this location
  char display();
  // player enters location
  void enter();
  // player leaves location
  void vacate();
};

#endif /* CELL_H_ */
