#ifndef BOARD_HXX
#define BOARD_HXX

#include <iostream>
#include <vector>
using namespace std;

#include "colors/osdepend.h"

#include "Ren.hxx"

class Board {
public:
  Board();
  Board(unsigned int, unsigned int, unsigned int);
  ~Board();
  const vector< vector<int> > getVector() const;
  int  getPos(int, int) const;
  void setPos(int, int, int);
  bool getState() const;
  void setState(bool);

  // Gameplay functions
  void printGame() const;
  void pick(int, int);

  // Functions
  void print() const;
  void debug(); 
private:
  /** Generates the board */
  void generate(unsigned int, unsigned int, unsigned int); 
  
  // Variables
  vector< vector<int> > mBoard; /** Hidden board */
  vector< vector<int> > mGame; /** Game view board */
  unsigned int mWidth;  /** width of the board */
  unsigned int mHeight; /** height of the board */
  unsigned int mBombs;  /** number of bombs */ 
  bool mState; /** Whether the game is being played or over */
  Ren mRen; /** multiplat. rand engine */ 
};


#endif 

