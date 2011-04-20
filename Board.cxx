#ifndef BOARD_CXX
#define BOARD_CXX

#include "Board.hxx"

Board::Board() : 
   mWidth(10)
  ,mHeight(10){
 
  unsigned int i, j;

  for (i=0; i<mWidth; ++i){
    mBoard.push_back(vector<int>());
    for (j=0; j<mHeight; ++j){
	  // 20% chance of a bomb placement 
	  mBoard[i].push_back( (mRen.getRandomNumber(100) < 20) ?  9 : 0);
	  if ( mBoard[i].back() == 9 ) {
	    /* calculations around bomb done here */
	  }
	}
  }

  /* Rank cells depending on adjacent bombs 
    -----
	-ooo- Only interested in the inside square
	-ooo- so we just start from x+1 y+1
	-----
  */

  // TODO This part needs major improvement  
/*  
  for (i=1; i<mWidth-1; ++i){
    for (j=1; j<mHeight; ++j){
      if (mBoard[i][j] != 9){ 
	    mBoard[i-1][j-1] == 9 ? ++mBoard[i][j] : 0;
	    mBoard[i][j-1]   == 9 ? ++mBoard[i][j] : 0;
	    mBoard[i+1][j-1] == 9 ? ++mBoard[i][j] : 0;
	    mBoard[i-1][j]   == 9 ? ++mBoard[i][j] : 0;
	    mBoard[i+1][j]   == 9 ? ++mBoard[i][j] : 0;
	    mBoard[i-1][j+1] == 9 ? ++mBoard[i][j] : 0;
	    mBoard[i][j+1]   == 9 ? ++mBoard[i][j] : 0;
	    mBoard[i+1][j+1] == 9 ? ++mBoard[i][j] : 0;
      }
    
	}
  }
*/
    /*
    oooo
	o--o  Now only interested in outter parts 
	o--o  of the board
	oooo  TODO
  */

}

Board::~Board(){} // I don't think I have to manually deallocate the vecs

void Board::setPos(int x, int y, int v){
  mBoard.at(x).assign(y, v);
}

int Board::getPos(int x, int y) const{
  return mBoard.at(x).at(y); 
}

const vector< vector<int> > Board::getVector() const{
  return mBoard;
}

void Board::print() const {

  for(vector< vector<int> >::const_iterator  it = mBoard.begin(); it != mBoard.end(); ++it){
    for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2){
	  if (*it2 == 9)
	    cout << "X";
	  else if (*it2 > 0)
	    cout << *it2; 
	  else
        cout << " ";
	}
	cout << endl;
  }
}

#endif

