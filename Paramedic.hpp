#pragma once
#include "Soldier.hpp"

using namespace std;

class Paramedic:public Soldier{
public:
 Paramedic(){};
 Paramedic(int num_player);
 ~Paramedic(){};
  void act (vector<vector<Soldier*>> & board,pair<int,int> location);
   int init_lifePoint();

};
