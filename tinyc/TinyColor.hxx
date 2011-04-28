#ifndef TINYCOLOR_HXX
#define TINYCOLOR_HXX

#include <iostream>
using namespace std;

#ifdef WINDOWS
  #include <windows.h>
#endif

/** Namespace to have our *safe* macros */
namespace tinyc {
  // Colors
  const unsigned int TC_BLA = 30;
  const unsigned int TC_RED = 31; 
  const unsigned int TC_CYA = 36;
  const unsigned int TC_GRY = 37;
  const unsigned int TC_BLU = 34; 
  const unsigned int TC_GRE = 32; 
  const unsigned int TC_MAG = 35; 
  const unsigned int TC_YEL = 33; 
  const unsigned int TC_WHI = 37;

  // Modes
  const unsigned int TC_NMOD = 22;
  const unsigned int TC_BMOD =  1;
  const unsigned int TC_UMOD =  4;
  const unsigned int TC_BLIN =  5;
  const unsigned int TC_BACK = 10;
}

/** Wrapper class for redundant code for coloring */
class TinyColor {
public:
  TinyColor();
  ~TinyColor();

#ifdef linux 
  template <typename T>
    void wc(T text, unsigned int cid){
	  wc(text, cid, tinyc::TC_NMOD);
	}
  template <typename T>
    void wc(T text, unsigned int cid, unsigned int mode){
      cout << "\033[";
	  cout << mode; // First 2 digits [xxdd]
	  cout << ";";
	  cout << cid; // Last two digits [ddxx]
	  cout << "m";
	  cout << text; 
      cout << "\033[0m"; 
	}
#elif WINDOWS
  template <typename T>
    void wc(T text, unsigned int cid, unsigned int mode){
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
        cout << text;
        SetConsoleTextAttribute(hConsole, 7);
	}
#else
  template <typename T>
    void wc(T text, unsigned int cid){
	  cout << "Your OS is not supported" << endl;
    }
#endif

private:

};
#endif
