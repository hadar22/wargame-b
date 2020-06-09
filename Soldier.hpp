#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

 enum Type{FootSold,FCommander,SniperS,SCommander,ParamedicS, PCommander};
class Soldier{
    
  protected:
   int _playerNum;
   int _lifePoint;
   int  _injuryPoint;
   Type _type;

    public:
    Soldier(){};
    virtual ~Soldier(){};

    virtual void act (vector<vector<Soldier*>> & board,pair<int,int> location)=0;
    int get_playerNum(){
        return _playerNum;
    }
    int get_lifePoint(){
        return _lifePoint;
    }
    int get_injuryPoint(){
      return _injuryPoint;
    }
    virtual int init_lifePoint()=0;
    void set_lifePoint(int lifeP){
        _lifePoint=lifeP;
    }
    Type get_type(){
    return _type;
}
double disCalc(int x1,int x2, int y1, int y2){
    double distX=pow((x1-x2),2);
    double distY=pow((y1-y2),2);
      return sqrt(distX+distY);
}
 
  
};





