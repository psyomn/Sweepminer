/**
 * \mainpage Sweepminer
 * \author psyomn
 * \section main What is Sweepminer
 * Sweepminer is just another minesweeper game written in C++ using
 * STL. 
 * \section done Done
 * All basic functionalities of a minesweeper game have been implemented.
 * \section todo Todo
 * Algorithm for 0's expansion, 
 * AI for hints
 */

#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Board.hxx"
#include "Ren.hxx"
#include "GameStats.hxx"

int main(){
  Board *b;
  GameStats gs;
  
  unsigned int px; // pick x - also used for width initialization
  unsigned int py; // pick y - also used for height initialization
  unsigned int nb; // num of bombs
  bool newgame = true;
  string str;
  string com; // for the commands

  cout << "Welcome to sweepminer!" << endl;
  cout << endl << " -- stats -- " << endl;
  gs.print();

  while(newgame){
    cout << "Enter board width  : ";
	cin >> px;
	cout << "Enter board height : ";
	cin >> py;
	cout << "Number of bombs    : ";
	cin >> nb;
	b = new Board(px, py, nb);
	
	while(b->getState()){
      cout << " - Game view - " << endl;
      b->printGame();

      cout << "sm::";
      cin >> com;

      switch(com[0]){
        case 'p': case 'P':
          cout << "X coordinate: ";
          cin >> px;
          cout << "Y coordinate: ";
          cin >> py;
	      b->pick(px, py);
          break;
        case 'h': case 'H':
          cout << "Options : " << endl;
          cout << "  p - pick a tile " << endl;
          cout << "  f - flag a tile " << endl;
          cout << "  a - ask the ai for a hint " << endl;
          break;
        case 'f': case 'F':
          cout << "Flag " << endl;
          cout << "x : "; cin >> px;
          cout << "y : "; cin >> py;
          b->flag(px,py);
          break;
        default:
          cout << "Something is wrong with your input" << endl;
          cout << "Try entering 'help' " << endl;
          break;
      }
     
	          
    }
    
	cout << "Game took " << b->getTime() << " seconds!" << endl;
    gs.tryTimeHighscore(b->getTime()); 

    b->getWin() ? gs.win() : gs.lose(); // Whether game was won or lost
	cout << ( b->getWin() ? "WIN!" : "lose." ) << endl;

    cout << " - Private view - " << endl;
    b->print();

	delete b; 

    gs.print();

	cout << "Play again ? [yes/no] : ";
	cin >> str;
	
	str == "yes" ? newgame=true : newgame=false;
  }
/*
  while(b.getState()) <- while game is ok.

*/

  return 0;
}
