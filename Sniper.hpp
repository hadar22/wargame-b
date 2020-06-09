#pragma once
#include "Soldier.hpp"

using namespace std;

class Sniper:public Soldier{
 
 public:
  Sniper(){};
  Sniper(int num_player);
   void act (vector<std::vector<Soldier*>> & board,pair<int,int> location);
   int init_lifePoint();
   ~Sniper(){};

};
