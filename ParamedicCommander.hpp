#pragma once
#include "Paramedic.hpp"

class ParamedicCommander:public Paramedic{
   public:
ParamedicCommander(){};
  ParamedicCommander(int num_player);
   ~ParamedicCommander(){};
  void act (vector<vector<Soldier*>> & board,pair<int,int> location);
     int init_lifePoint();


};
