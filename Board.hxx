#ifndef BOARD_HXX
#define BOARD_HXX

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#include "tinyc/TinyColor.hxx"

#include "Ren.hxx"

class Board {
public:
  Board();
  Board(unsigned int, unsigned int, unsigned int);
  ~Board();
  const vector< vector<int> > getVector() const;
  int getPos(int, int) const;
  void setPos(int, int, int);
  bool getState() const;
  void setState(bool);
  time_t getTime();
  bool getWin();

  // Gameplay functions
  void printGame() const;
  void pick(int, int);
  void pick(unsigned int, unsigned int);

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
  unsigned int mScore;  /** Total uncovered tiles */
  bool mState; /** Whether the game is being played or over */
  bool mWin; /** Whether the game was won or lost. */
  Ren mRen; /** multiplat. rand engine */ 
  time_t mStartTime; /** Record the beginning time */
};


#endif 

