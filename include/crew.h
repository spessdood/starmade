#ifndef CREW_H
#define CREW_H
#include <stdlib.h>
#include <string>
#include <vector>
#include <utility>

class Crew{
  std::string Name,Race;
  int Skills[5];//0:Combat,1:Repair,2:Driving,3:Weapons,4:Shields
  int SkillProgress[5];

};

#endif
