#ifndef BOARD_HXX
#define BOARD_HXX

#include <iostream>
#include <vector>
using namespace std;

#include "Ren.hxx"

class Board {
public:
  Board();
  ~Board();
  const vector< vector<int> > getVector() const;
  int  getPos(int, int) const;
  void setPos(int, int, int);

  // Functions
  void print() const;
private:
  vector< vector<int> > mBoard;
  unsigned int mWidth;
  unsigned int mHeight;
  Ren mRen; // one random engine for all.  
};


#endif 

