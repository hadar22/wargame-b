#include "Sniper.hpp"


#define NUM_LIFE 100

Sniper::Sniper(int num_player){
     _playerNum=num_player;
     _lifePoint=NUM_LIFE;
     _injuryPoint=50;
     _type=Type::SniperS;
}



  void Sniper::act (std::vector<std::vector<Soldier*>> & board,pair<int,int> location){
     Soldier *soldierInjured=nullptr;
     pair<int,int> locInjured;
     int col=board.size();
     int row=board[0].size();
     double maxPoint=0;
     for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
             if (board[i][j]!= nullptr){
                 Soldier* temp=board[i][j];
                 if(temp->get_playerNum() != this->get_playerNum()){
                     int d=temp->get_lifePoint();
                     if(d>maxPoint){
                         maxPoint=d;
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
  int Sniper::init_lifePoint(){
      return NUM_LIFE;
  }
 