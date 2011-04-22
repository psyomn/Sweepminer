#ifndef BOARD_CXX
#define BOARD_CXX

#include "Board.hxx"

/* default constructor */
Board::Board() : mWidth(15), mHeight(10), mBombs(10), mState(true){
  generate(mWidth,mHeight,mBombs);
}

/* Constructor for entering values on the fly */
Board::Board(unsigned int x, unsigned int y, unsigned int b) : mState(true){
  generate(x,y,b);
}

/* Generic generation function. */
void Board::generate(unsigned int x, unsigned int y, unsigned int b){
  unsigned int i, j;
  unsigned int rx, ry;
  unsigned int top;
  unsigned int left;
  unsigned int right;
  unsigned int bottom;

  mWidth  = x;
  mHeight = y;
  mBombs  = b;

  for(i=0; i<mHeight; ++i){
    mBoard.push_back(vector<int>(mWidth,0));
	mGame.push_back(vector<int>(mWidth,-1));
  }

  for(j=0; j<mBombs; ++j){
    rx = mRen.getRandomNumber(mWidth);
	ry = mRen.getRandomNumber(mHeight);
	
	if (mBoard[ry][rx] < 9){ // in case we fall somewhere there is already a bomb.
	  mBoard[ry][rx] = 9;

      /* Now we need only to check the surrounding stuffs */
	  top    = ry == 0 ? 0 : 1;
	  bottom = ry == mHeight-1 ? 0 : 1;
	  left   = rx == 0 ? 0 : 1;
	  right  = rx == mWidth-1 ? 0 : 1;

	  // top three exist? 
      if(top){
	    ++mBoard[ry - top][rx];
	    if (left)  ++mBoard[ry - top][rx - left];
	    if (right) ++mBoard[ry - top][rx + right];
      }

	  // left right exist ?
	  if(left)  ++mBoard[ry][rx - left];
	  if(right) ++mBoard[ry][rx + right];

	  // bottom three exist?
	  if(bottom){
	    ++mBoard[ry + bottom][rx];
	    if(right) ++mBoard[ry + bottom][rx + right];
	    if(left)  ++mBoard[ry + bottom][rx - left];
	  }
	}
	else
	  --j;
  }

  /* Note: the above will make bombs of 9 in some cases > 9. We do not care
  since if one tile is surrounded by max bombs, it will only be 8 at worst.
  Therefore in the printing algorithm, we simply specify > 8 to print 'X' */

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

/* Printing function for the board */
void Board::print() const {
  // y, then x
  for(vector< vector<int> >::const_iterator  it = mBoard.begin(); it != mBoard.end(); ++it){
    for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2){
	  if (*it2 > 8)
	    wc("X", RED);
	  else if (*it2 > 0)
	    switch(*it2){
		  case 1: wc("1", GREEN);   break;
		  case 2: wc("2", BLUE);    break;
		  case 3: wc("3", LGREEN);  break;
		  case 4: wc("4", MAGENTA); break;
		  case 5: wc("5", BROWN);   break; 
		  case 6: wc("6", CYAN);    break; 
		  case 7: wc("7", GREY);    break;
		}
	  else
        cout << " ";
	}
	cout << endl;
  }
}

/** Used for simple debugging */
void Board::debug(){

  for(vector< vector<int> >::const_iterator  it = mBoard.begin(); it != mBoard.end(); ++it){
    cout << ". ";
    for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2){
	  cout << *it2; 
      cout << " ";
	}
	cout << endl;
  }
  cout << "Height: " << mBoard.size() << endl;
  cout << "Width:" << mBoard[0].size() << endl;
}

/** Return whether the game is being played or not */
bool Board::getState() const {
  return mState;
}

/** Set the state of the game 
\param s state of the game
*/
void Board::setState(bool s) {
  mState = s;
}

/** This prints the game view */
void Board::printGame() const {
  // y, then x
  for(vector< vector<int> >::const_iterator  it = mGame.begin(); it != mGame.end(); ++it){
    for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2){
	  if (*it2 > 8)
	    wc("X", RED);
	  else if (*it2 > 0)
	    switch(*it2){
		  case 1: wc("1", GREEN);   break;
		  case 2: wc("2", BLUE);    break;
		  case 3: wc("3", LGREEN);  break;
		  case 4: wc("4", MAGENTA); break;
		  case 5: wc("5", BROWN);   break; 
		  case 6: wc("6", CYAN);    break; 
		  case 7: wc("7", GREY);    break;
		}
	  else if (*it2 < 0)
	    wc("?", WHITE);
	  else
        cout << " ";
	}
	cout << endl;
  } 
}

/** picking function for a tile 
\param x is for x coord.
\param y is for y coord. */
void Board::pick(int x, int y){
  bool ok;
  
  x > mWidth - 1  ? ok = false : ok = true;
  x < 0           ? ok = false : ok = true;
  y > mHeight - 1 ? ok = false : ok = true;
  y < 0           ? ok = false : ok = true;

  if (ok) {
    mGame[y][x] = mBoard[y][x];
	if (mGame[y][x] >= 9){
	  mState = false;
	  wc("BOOM! YOU ARE DEAD! NO BIG SURPRISE!\n", RED);
	}
  } else {
    cout << "There's something wrong with the coordinates you put" << endl;
  }
}

#endif

