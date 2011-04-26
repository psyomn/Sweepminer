#ifndef GAMESTATS_HXX
#define GAMESTATS_HXX

#include <iostream>
#include <ctime>
using namespace std;

/** Simple class to store different game stats.
\author psyomn  */

class GameStats {
public: 
  GameStats();
  ~GameStats();
  void win();
  void lose();
  void tryTimeHighscore(time_t);
  void print();
  unsigned int getPlayed();
  unsigned int getWon();
  unsigned int getLost();
  time_t getTime();
private:
  unsigned int mGamesWon;
  unsigned int mGamesPlayed;
  time_t mTimeTook;
  void setTime(time_t);
};

#endif

