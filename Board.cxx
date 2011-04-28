#ifndef BOARD_CXX
#define BOARD_CXX

#include "Board.hxx"

/** default constructor */
Board::Board() : mWidth(15), mHeight(10), mBombs(10), mScore(0), mState(true), mWin(false), mStartTime(time(0)){
  generate(mWidth,mHeight,mBombs);
}

/** Constructor for entering values on the fly */
Board::Board(unsigned int x, unsigned int y, unsigned int b) : mScore(0), mState(true), mWin(false), mStartTime(time(0)){
  generate(x,y,b);
}

/** Generic generation function. */
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

/** Default destructor */
Board::~Board(){} // I don't think I have to manually deallocate the vecs

/** Set the position with a specific value */
void Board::setPos(int x, int y, int v){
  mBoard.at(x).assign(y, v);
}

/** Get the positions specific value */
int Board::getPos(int x, int y) const{
  return mBoard.at(x).at(y); 
}

/** Return a constant instance of the vector we're using as a board */
const vector< vector<int> > Board::getVector() const{
  return mBoard;
}

/** Printing function for the board */
void Board::print() const {
  // y, then x
  TinyColor tc;
  for(vector< vector<int> >::const_iterator  it = mBoard.begin(); it != mBoard.end(); ++it){
    for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2){
	  if (*it2 > 8)
	    tc.wc("X", tinyc::TC_RED);
	  else if (*it2 > 0)
	    switch(*it2){
		  case 1: tc.wc("1", tinyc::TC_GRE); break;
		  case 2: tc.wc("2", tinyc::TC_BLU); break;
		  case 3: tc.wc("3", tinyc::TC_YEL); break;
		  case 4: tc.wc("4", tinyc::TC_MAG); break;
		  case 5: tc.wc("5", tinyc::TC_YEL); break; 
		  case 6: tc.wc("6", tinyc::TC_CYA); break; 
		  case 7: tc.wc("7", tinyc::TC_GRY); break;
		  case 8: tc.wc("8", tinyc::TC_GRY); break;
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
  cout << "Height : " << mBoard.size() << endl;
  cout << "Width  : " << mBoard[0].size() << endl;
  cout << "Score  : " << mScore << endl;
}

/** Return whether the game is being played or not */
bool Board::getState() const {
  return mState;
}

/** Set the state of the game. True means, game is ongoing. False means game
is done. \param s state of the game
*/
void Board::setState(bool s) {
  mState = s;
}

/** This prints the game view */
void Board::printGame() const {
  TinyColor tc;
  // y, then x
  for(vector< vector<int> >::const_iterator  it = mGame.begin(); it != mGame.end(); ++it){
    for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2){
	  if (*it2 > 8)
	    tc.wc("X", tinyc::TC_RED);
	  else if (*it2 > 0)
	    switch(*it2){
		  case 1: tc.wc("1", tinyc::TC_GRE); break;
		  case 2: tc.wc("2", tinyc::TC_BLU); break;
		  case 3: tc.wc("3", tinyc::TC_YEL); break;
		  case 4: tc.wc("4", tinyc::TC_MAG); break;
		  case 5: tc.wc("5", tinyc::TC_YEL); break; 
		  case 6: tc.wc("6", tinyc::TC_CYA); break; 
		  case 7: tc.wc("7", tinyc::TC_GRY); break;
		}
	  else if (*it2 < 0)
	    tc.wc("?", tinyc::TC_WHI);
	  else
        cout << " ";
	}
	cout << endl;
  } 
}

/** Interface for int input 
\param x interger value. If negative, the absolute value is found and passed on
\param y interger value. If negative, the absolute value is found and passed on
*/
void Board::pick(int x, int y){
  unsigned int xx; 
  unsigned int yy;

  x < 0 ? xx = -x : xx = x;
  y < 0 ? yy = -y : yy = y;

  pick(xx, yy); // Send off the unsigned int values
}

/** picking function for a tile 
\param x is for x coord.
\param y is for y coord. */
void Board::pick(unsigned int x, unsigned int y){
  TinyColor tc;
  bool ok;

  x > mWidth  - 1 ? ok = false : ok = true;
  y > mHeight - 1 ? ok = false : ok = true;

  // If coordinates inserted are ok
  if (ok) {
	if (mBoard[y][x] >= 9){
	  mState = false;
	  tc.wc("BOOM! YOU ARE DEAD! NO BIG SURPRISE!\n", tinyc::TC_RED);
	}
	else{
	  if (mGame[y][x] == -1){ 
	    ++mScore; // increment uncovered tile number
	    mGame[y][x] = mBoard[y][x];
      }
	  // check to see if game is complete
	  if ( mWidth*mHeight - mBombs == mScore ){
	    mState = false;
		mWin = true;
	  }

	}
  
  } else {
    cout << "There's something wrong with the coordinates you put" << endl;
  }
}

/** Return the amount of seconds this game took */
time_t Board::getTime(){
  return time(0) - mStartTime; 
}

/** \return mWin to see if the game was won or not. */
bool Board::getWin(){
  return mWin;
}

#endif

