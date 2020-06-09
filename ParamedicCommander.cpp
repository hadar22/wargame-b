#include "ParamedicCommander.hpp"

 
#define NUM_LIFE 200

ParamedicCommander::ParamedicCommander(int num_player){
     _playerNum=num_player;
     _lifePoint=NUM_LIFE;
     _injuryPoint=0;
     _type=Type::PCommander;
}
void ParamedicCommander::act (std::vector<std::vector<Soldier*>> & board,pair<int,int> location){
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
for (int i=0; i<row;i++){
    for(int j=0;j<col;j++){
        if(board[i][j]!=nullptr){
            Soldier* temp=board[i][j];
            if(temp->get_playerNum() == this->get_playerNum()){
                if(temp->get_type()==ParamedicS){
                    temp->act(board,{i,j});
                }
            }
        }
    }
}
}
 int ParamedicCommander::init_lifePoint(){
      return NUM_LIFE;
  }
 