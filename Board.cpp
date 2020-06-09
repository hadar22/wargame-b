#include "Board.hpp"
using namespace std;
using namespace WarGame;
       
       Soldier*& Board::operator[](pair<int,int> location){
           
           return board[location.first][location.second];
       }
       Soldier* Board::operator[](pair<int,int> location) const{
           return board[location.first][location.second];
       }
       
       void Board::move(int player_number,pair<int,int> source,Board::MoveDIR direction){
           int row=board.size();
           int col=board[0].size();
           if(source.first>=row|| source.second>=col || source.first<0 || source.second<0){
               throw invalid_argument("off the board");
           }
           
           if(board[source.first][source.second]==nullptr){
               throw invalid_argument("there is no soldier there ");
           }
           Soldier *soldier=board[source.first][source.second];
           if (soldier->get_playerNum()!= player_number){
               throw invalid_argument("not the same player's soldier");
           }
           pair<int,int> moveto;
           moveto.first=source.first;
           moveto.second= source.second;
           switch(direction){
               case MoveDIR::Up:
                    moveto.first=moveto.first+1;
                    break;

               case MoveDIR::Down:
                    moveto.first=moveto.first-1;
                    break;

               case MoveDIR::Right:
                    moveto.second=moveto.second+1;
                    break;

               case MoveDIR::Left:
                    moveto.second=moveto.second-1;
                    break;
                default:
                   break;

           }
           if(0>moveto.first || moveto.first>=row || 0>moveto.second || moveto.second >=col){
               throw invalid_argument("off the board");
           }
           
           if (board[moveto.first][moveto.second] != nullptr ){
               throw invalid_argument("there is soldier there ");
           }
           board[moveto.first][moveto.second]=soldier;
           board[source.first][source.second]=nullptr;
           soldier->act (board,moveto);
       }
       bool Board::has_soldiers(uint player_number) const{
            for(int i=0; i< board.size();i++){
                for (int j=0; j<board[i].size();j++){
                    if(board[i][j]!=nullptr && board[i][j]->get_playerNum()==player_number ){
                        
                               return true;
                    } 
                }
            }
            return false;
           
       } 
    

