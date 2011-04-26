#ifndef GAMESTATS_CXX
#define GAMESTATS_CXX

#include "GameStats.hxx"

/** Default constructor. Initialize all to zero. */
GameStats::GameStats() : mGamesWon(0), mGamesPlayed(0){}

/** Default destructor. Nothing to deallocate */
GameStats::~GameStats(){}

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
  t >= mTimeTook ? 0 : mTimeTook = t;
}

void GameStats::print(){
  cout << "Times Won     : " << mGamesWon << endl;
  cout << "Times Lost    : " << mGamesPlayed - mGamesWon << endl;
  cout << "Times Played  : " << mGamesPlayed << endl;
  cout << "Shortest time : " << mTimeTook << endl;
}


#endif

