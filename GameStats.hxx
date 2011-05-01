#ifndef GAMESTATS_HXX
#define GAMESTATS_HXX

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
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
  void save();
  void load();
  void startTimer();
  unsigned int getPlayed();
  unsigned int getWon();
  unsigned int getLost();
  time_t getTime();
  double percentWin();
  double percentLose();
private:
  unsigned int mGamesWon; /** Number of games won */
  unsigned int mGamesPlayed; /** Number of games played */
  time_t mTimeTook; /** Time taken to complete a game */
  void setTime(time_t); /** Main method to set the time if won */
  static string mSaveFile; 
};

#endif

