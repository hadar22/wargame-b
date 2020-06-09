#include "FootSoldier.hpp"

#define NUM_LIFE 100

FootSoldier::FootSoldier(int num_player){
     _playerNum=num_player;
     _lifePoint=NUM_LIFE;
     _injuryPoint=10;
     _type=Type::FootSold;
}



  void FootSoldier::act (vector<vector<Soldier*>> & board,pair<int,int> location){
     Soldier* soldierInjured=nullptr;
     pair<int,int> locInjured;
     int col=board.size();
     int row=board[1].size();
     double short_distance=row*col;
     for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
             if (board[i][j]!= nullptr){
                 Soldier* temp=board[i][j];
                 if(temp->get_playerNum() != this->get_playerNum()){
                     double d=this->disCalc(locInjured.first,i,locInjured.second,j);
                     if(d<short_distance){
                         short_distance=d;
                         soldierInjured=temp;
                         locInjured={i,j};
                     }
                 }

             }

         }
     }
     if(soldierInjured!=nullptr){
         int newPoint=soldierInjured->get_lifePoint() - this->get_injuryPoint();
         if(newPoint<=0){
             board[locInjured.first][locInjured.second]=nullptr;
         }
         else{
             soldierInjured->set_lifePoint(newPoint);
         }
     }
  }
  int FootSoldier::init_lifePoint(){
      return NUM_LIFE;
  }
