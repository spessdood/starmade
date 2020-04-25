#ifndef FLEET_H
#define FLEET_H
#include <stdlib.h>
#include <string>
#include <vector>
#include <utility>
#include "crew.h"
#include "weapon.h"

class Ship{
public:
  int MaxHull,Hull,Energy,CargoCap,MaxCrew;
  std::vector<
    std::pair<
      std::string,int>> Cargo;
  Crew Crews[10];
  Weapon Weapons[10];
  Ship(std::string Model);
};



class Fleet{
public:
  std::string Name;
  std::pair<int,int> pos;
  int angle,speed,topSpeed;
  std::vector<Ship> Ships;


};




#endif
