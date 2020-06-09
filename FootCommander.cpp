#include "FootCommander.hpp"

#define NUM_LIFE 150

using namespace std;

FootCommander::FootCommander(int num_player){
    _playerNum=num_player;
     _lifePoint=NUM_LIFE;
     _injuryPoint=20;
     _type=Type::FCommander;
}
 
  void FootCommander::act (vector<vector<Soldier*>> & board,pair<int,int> location){
         vector <Soldier*> AllFootSol;
     vector <pair<int,int>> AllLocation;
     Soldier *CloseEnrmy=nullptr;
     pair<int,int> enemyLocation;
     int col=board.size();
     int row=board[1].size();
     double short_distance=row*col;
     for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
             if (board[i][j]!= nullptr){
                 Soldier* temp=board[i][j];
                 if(temp->get_playerNum() != this->get_playerNum()){
                     double d=this->disCalc(location.first,i,location.second,j);
                     if(d<short_distance){
                         short_distance=d;
                         CloseEnrmy=temp;
                         enemyLocation={i,j};
                     }
                 }
             else if(temp->get_type()==FootSold){
                 AllFootSol.push_back(temp);
                 AllLocation.push_back({i,j});

             }

             }

         }
     }
     if(CloseEnrmy !=nullptr){
         int newPoint=CloseEnrmy->get_lifePoint() - this->get_injuryPoint();
         if(newPoint<=0){
             board[location.first][location.second]=nullptr;
         }
         else{
             CloseEnrmy->set_lifePoint(newPoint);
         }
     }
     for(int i=0;i<AllFootSol.size();i++){
         AllFootSol[i]->act(board,AllLocation[i]);
     }


  }
   int FootCommander:: init_lifePoint(){
         return NUM_LIFE;
   }
