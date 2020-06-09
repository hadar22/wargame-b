#pragma once
#include "FootSoldier.hpp"

using namespace std;
class FootCommander:public FootSoldier{
 

  public:
  FootCommander(int num_player);
   ~FootCommander(){};
  void act (vector<vector<Soldier*>> & board,pair<int,int> location);
   int init_lifePoint();
 
};
