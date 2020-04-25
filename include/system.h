#ifndef SYSTEM_H
#define SYSTEM_H
#include <stdlib.h>
#include "fleet.h"
#include <string>
#include <vector>
#include <utility>
class World{
  public:
    int Pop,Stability;
    std::string Name,Type,Faction;
    std::pair<int,int> pos;
    void Process();

  private:

};


struct Structure{
  std::string Type,Faction,Name;
  std::pair<int,int> pos;
};

struct System{
  std::string Star,Name;
  World Worlds[7];
  Structure Structures[7];
  std::vector<
    std::pair<
      std::string,int>> Cargo;
};



#endif
