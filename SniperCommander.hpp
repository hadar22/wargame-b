#pragma once
#include "Sniper.hpp"

using namespace std;
class SniperCommander:public Sniper{
 

  public:
  SniperCommander(int num_player);
 ~SniperCommander(){};
   void act (vector<vector<Soldier*>> & board,pair<int,int> location);
  int init_lifePoint();

};
