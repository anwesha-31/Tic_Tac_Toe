#include<bits/stdc++.h>
using namespace std;
char square_board[9]={'1','2','3','4','5','6','7','8','9'};
string player1,player2;
int marked_box;
char turn='X';
bool draw=false;
int choice;

  /***********************************************************
        FUNCTION TO DRAW THE TIC TAC TOE GAME BOARD 
  ************************************************************/
void board(){
  system("cls");
  cout<<"\t\t TIC TAC TOE GAME\n";
  cout<<"\t\t PLAYER-1 [X] \t PLAYER-2 [O]\n";
  cout<<"\t\t\t     |     |     \n"; 
  cout<<"\t\t\t  "<<square_board[0]<<"  |  "<<square_board[1]<<"  |  "<<square_board[2]<<"  \n";
  cout<<"\t\t\t_____|_____|_____\n";
  cout<<"\t\t\t     |     |     \n";
  cout<<"\t\t\t  "<<square_board[3]<<"  |  "<<square_board[4]<<"  |  "<<square_board[5]<<"  \n";
  cout<<"\t\t\t_____|_____|_____\n";
  cout<<"\t\t\t     |     |     \n";
  cout<<"\t\t\t  "<<square_board[6]<<"  |  "<<square_board[7]<<"  |  "<<square_board[8]<<"  \n";
  cout<<"\t\t\t     |     |     \n";
}

  /*************************************************************
            FUNCTION FOR MARKING CHOICES AND SWITCHING TURNS 
  **************************************************************/
void player_turn(){

  if(turn=='X') cout<<"\t\t PLAYER-1 [X] turn --> \n";
  else cout<<"\t\t PLAYER-2 [O] turn --> \n";

  cin>>choice;
  switch(choice){
    case 1: marked_box=0; break;
    case 2: marked_box=1; break;
    case 3: marked_box=2; break;
    case 4: marked_box=3; break;
    case 5: marked_box=4; break;
    case 6: marked_box=5; break;
    case 7: marked_box=6; break;
    case 8: marked_box=7; break;
    case 9: marked_box=8; break;
    default : cout<<"INVALID CHOICE"; break;
  }
  if(turn=='X' && square_board[marked_box]!='O' && square_board[marked_box]!='X'){
    square_board[marked_box]='X';
    turn='O';
  }
  else if(turn=='O'  && square_board[marked_box]!='O' && square_board[marked_box]!='X'){
    square_board[marked_box]='O';
    turn='X';
  }
  board();
}

  /**************************************************
          FUNCTION TO CHECK IF THE GAME IS OVER
          1. GAME IS OVER WHEN ANYONE WINS
          2. GAME IS NOT OVER AND THERE ARE BOXES LEFT TO BE MARKED
          3. ALL BOXES ARE FILLED AND NO SIDE HAS WON  
  ***************************************************/
bool gameOver(){
  /**************************************************
            check win
            1. row-wise
            2. column-wise
            3. diagonally 
  ***************************************************/ 
  for(int i=0;i<9;i=i+3) if(square_board[i]==square_board[i+1] && square_board[i]==square_board[i+2]) return true; 
  for(int i=0;i<3;i++) if(square_board[i]==square_board[i+3] && square_board[i]==square_board[i+6]) return true;
  if(square_board[0]==square_board[4] && square_board[0]==square_board[8]) return true;
  if(square_board[2]==square_board[4] && square_board[2]==square_board[6]) return true;
  /**************************************************
            check if boxes are unfilled 
  ***************************************************/
  for(int i=0;i<9;i++) if(square_board[i]!='X'&& square_board[i]!='O') return false; 
  /**********************************************************
      draw situation encountered with all the boxes marked by players
  ***********************************************************/
  draw=true;
  return true;
}

int main(){
  cout<<"ENTER THE NAME OF THE PLAYERS";
  cin>>player1>>player2;
  transform(player1.begin(), player1.end(), player1.begin(), ::toupper);
  transform(player2.begin(), player2.end(), player2.begin(), ::toupper);
  while(!gameOver()){
  board();
  player_turn();
  gameOver();
  }
  if(turn=='X' && draw==false) cout<<player2<<" WINS !! CONGRATULATIONS";
  else if(turn=='O' && draw==false) cout<<player1<<" WINS !! CONGRATULATIONS";
  else cout<<"DRAW !!!!";
}
