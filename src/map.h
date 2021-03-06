/*
 * map.h
 *
 *      Author: Carter
 */

#ifndef MAP_H_
#define MAP_H_

// the following line (declaration) ensures do not to include cell.h
class MapCell;


// Track the area the robot in which the robot moves.
// Note you will need to add declarations for the height and width.
// Add other methods and data as needed.
class Map {
public:
  int playerx, playery, wumpusx, wumpusy;
  MapCell *cells[6][6];
  // initialize empty map
  Map();
  // make debug map
  void debugLoad();
  // read the map from randomization
  void load();
  // write the full map to cout
  void write();
  //writes empty map with player
  void writePlayer();
};

#endif /* MAP_H_ */
