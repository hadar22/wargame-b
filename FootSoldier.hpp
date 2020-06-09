#pragma once
#include "Soldier.hpp"


  class FootSoldier:public Soldier{
 
public:
  FootSoldier(){};
   ~FootSoldier(){};
  FootSoldier(int num_player);
   void act (vector<vector<Soldier*>> & board,pair<int,int> location);
   int init_lifePoint();
   void print();
};

