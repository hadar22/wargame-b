#include "Paramedic.hpp"

#define NUM_LIFE 100

Paramedic::Paramedic(int num_player){
     _playerNum=num_player;
     _lifePoint=NUM_LIFE;
     _injuryPoint=0;
     _type=Type::ParamedicS;
}
void Paramedic::act (std::vector<std::vector<Soldier*>> & board,pair<int,int> location){
  int x= location.first;
  int y= location.second;
  int row=board.size();
  int col=board[0].size();
for(int i=x-1 ; i<= x+1; i++){
    for (int j=y-1 ;j<=y+1; j++){
        if(i<row &&j<col){
            if(!(i==x&& j==y)){
                Soldier* temp=board[i][j];
                if(temp != nullptr){
                    uint initPoint=temp->init_lifePoint();
                    temp->set_lifePoint(initPoint);
                }
            }
        }
    }
}
}
 int Paramedic::init_lifePoint(){
      return NUM_LIFE;
  }
 