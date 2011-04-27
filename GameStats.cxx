#ifndef GAMESTATS_CXX
#define GAMESTATS_CXX

#include "GameStats.hxx"

string GameStats::mSaveFile = "save.dat";

/** Default constructor. Initialize all to zero. */
GameStats::GameStats() : mGamesWon(0), mGamesPlayed(0), mTimeTook(0){
  load();
}

/** Default destructor. Nothing to deallocate */
GameStats::~GameStats(){
  save();
}

/** Increment the total amount of games played and lost. */
void GameStats::win(){
  ++mGamesWon;
  ++mGamesPlayed;
}

/** Just increment the amount of games. The variable 'lost games' can be
found using a simple calculation of substraction */
void GameStats::lose(){
  ++mGamesPlayed;
}

/** Start the timer (maybe this will be removed later...) */
void GameStats::startTimer(){
}

/** Get the number of games the player has won. */
unsigned int GameStats::getWon(){
  return mGamesWon;
}

/** Get the amount of games played.  */
unsigned int GameStats::getPlayed(){
  return mGamesPlayed;
}

/** Get the amount of games lost */
unsigned int GameStats::getLost(){
  return mGamesPlayed - mGamesWon;
}

/** Get time taken */
time_t GameStats::getTime(){
  return mTimeTook;
}

/** Set time taken */
void GameStats::setTime(time_t st){
  mTimeTook = st;
}

/** Check and see if the time highscore is broken */
void GameStats::tryTimeHighscore(time_t t){
  t >= mTimeTook && mTimeTook != 0 ? 0 : mTimeTook = t;
}

/** Print the game statistics */
void GameStats::print(){
  cout << "Times Won     : " << mGamesWon << endl;
  cout << "Times Lost    : " << mGamesPlayed - mGamesWon << endl;
  cout << "Times Played  : " << mGamesPlayed << endl;
  cout << "Shortest time : " << mTimeTook << endl;
}

/** Save data inside a binary file \see mSaveFile */
void GameStats::save(){
  ofstream ofs;
  
  ofs.open(mSaveFile.c_str(), ios::binary | ios::out);

  if (ofs){
    ofs.write( (const char*) &mGamesWon, sizeof(mGamesWon));
	ofs.write( (const char*) &mGamesPlayed, sizeof(mGamesPlayed));
	ofs.write( (const char*) &mTimeTook, sizeof(mTimeTook));
	cout << "Wrote save" << endl;
  }
}

/** Load data from binary file \see mSaveFile */
void GameStats::load(){
  ifstream ifs;

  ifs.open(mSaveFile.c_str(), ios::binary | ios::in);
  
  if (ifs){
    ifs.read( (char*) &mGamesWon, sizeof(mGamesWon));
	ifs.read( (char*) &mGamesPlayed, sizeof(mGamesPlayed));
	ifs.read( (char*) &mTimeTook, sizeof(mTimeTook));
	cout << "Load save" << endl;
  }
}

#endif

