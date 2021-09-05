#include <bits/stdc++.h>
using namespace std;

char square[9]={'0','1','2','3','4','5','6','7','8'};

void board()
{

		cout << "Player [X]  -  COMPUTER [O]" << endl << endl;
		cout << endl;
	
		cout << "     |     |     " << endl;
		cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;
	
		cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;
	
		cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;

		cout << "     |     |     " << endl << endl;
}

int game(){
  if (square[0] == square[1] && square[1] == square[2]) return 1;
	else if (square[3] == square[4] && square[4] == square[5]) return 1;
	else if (square[6] == square[7] && square[7] == square[8]) return 1;
	else if (square[0] == square[3] && square[3] == square[6]) return 1;
	else if (square[1] == square[4] && square[4] == square[7]) return 1;
	else if (square[2] == square[5] && square[5] == square[8]) return 1;
	else if (square[0] == square[4] && square[4] == square[8]) return 1;
	else if (square[2] == square[4] && square[4] == square[6]) return 1;


	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'  && square[4] != '4' && square[5] != '5' && square[6] != '6'  && square[7] != '7' && square[8] != '8' && square[9] != '9')	return 0;


	else
			return -1;
  
}


int mark(int choice,int turn){
  char ch;
  if(turn==1) ch = 'X'; else ch='O';

  if(choice==0 && square[0]=='0') square[0] = ch;
  else if(choice==1 && square[1]=='1') square[1] = ch;
  else if(choice==2 && square[2]=='2') square[2] = ch;
  else if(choice==3 && square[3]=='3') square[3] = ch;
  else if(choice==4 && square[4]=='4') square[4] = ch;
  else if(choice==5 && square[5]=='5') square[5] = ch;
  else if(choice==6 && square[6]=='6') square[6] = ch;
  else if(choice==7 && square[7]=='7') square[7] = ch;
  else if(choice==8 && square[8]=='8') square[8] = ch;
  else {
    if(turn==1) cout<<"Invalid Move"<<endl;
    return 0;
  }
  return 1;
}

int minimax(int who){
  int win = game();
  if(win==1){
    if(who==0) return 5;
    else return -5;
  } 
  
  if(win==0) return 0;


  //ye computer ka turn h

  if(who!=0){
    int best=INT_MIN;
    for(int i=0;i<9;i++){
      if(i == (square[i]-'0')){
        mark(i,0);
        best = max(minimax(0),best);
        square[i]=i+'0';
      }
    }
   return best;
  }

  else if(who==0){
    int best=INT_MAX;
    for(int i=0;i<9;i++){
      if(i == (square[i]-'0')){
        mark(i,1);
        best = min(minimax(1),best);
        square[i]=i+'0';
      }
    }
   return best;
  }


}


int comp(){
  int bestMove = INT_MIN;
  int index; //result move ke liye
  int move=0;
  for(int i=0;i<9;i++){
    if(i == (square[i]-'0')){
      mark(i,0);
      move = minimax(0);
      square[i]=i+'0';
      if(move>bestMove){
        bestMove=move;
        index = i;
        if(bestMove == 5) break;
      }

    }
  }
  mark(index,0);
  board();
  return game();
}



void solve(int r){
  int k ;
  int choice;
  while(r==-1){
    cout<<"Enter your choice"<<endl;
    while(1){    // jab tk shi choice na daale
      cin>>choice;
      k = mark(choice,1);
      if(k!=0) break;
    }
    board();
    r = game();
    if(r==1){
      cout<<"YOU WIN ! CONGRATULATIONS :)";
      break;
    } 
    else if(r==0){
      cout<<"IT'S A DRAW !";
      break;
    } 

    r = comp(); //ai wala function
    if(r==1){
      cout<<"COMPUTER WINS ! BETTER LUCK NEXT TIME :)";
      break;
    } 
    else if(r==0){
      cout<<"IT'S A DRAW !";
      break;
    }
  }
}


int main() {
  board();
  solve(-1);
}