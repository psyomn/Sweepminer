#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Board.hxx"
#include "Ren.hxx"

int main(){
  Board *b;
  
  unsigned int px; // pick x - also used for width initialization
  unsigned int py; // pick y - also used for height initialization
  unsigned int nb; // num of bombs
  bool newgame = true;
  string str;

  cout << "Welcome to sweepminer!" << endl;

  while(newgame){
    cout << "Enter board width  : ";
	cin >> px;
	cout << "Enter board height : ";
	cin >> py;
	cout << "Number of bombs    : ";
	cin >> nb;
	b = new Board(px, py, nb);
	
	while(b->getState()){
      cout << " - Private view - " << endl;
      b->print();
      cout << " - Game view - " << endl;
      b->printGame();
      
	  cout << "X coordinate: ";
      cin >> px;
      cout << "Y coordinate: ";
      cin >> py;
      
	  b->pick(px, py);
    }
    delete b; 

	cout << "Play again ? [yes/no] : ";
	cin >> str;
	
	str == "yes" ? newgame=true : newgame=false;
  }
/*
  while(b.getState()) <- while game is ok.

*/

  return 0;
}
