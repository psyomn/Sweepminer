/******************************************************************************
* @file 
* @author Simon
*
* @brief Small snippet that allows for colors to be shown on linux terminals.
*
* @section DESCRIPTION
*
* Linux uses a special escape character in order to print in colors. So this
* will simple return the character that is needed to print the color. Linux
* also has other flexibilities such as to print the font bold or not.
*
* This code snippet was used from another (discontinued) project of mine 
* called Darkrunner which is availabled under GPL on sf.net.
******************************************************************************/

/*

 Escape sequences for colors in Lunix OSs...

\033[22;30m - black
\033[22;31m - red
\033[22;32m - green
\033[22;33m - brown
\033[22;34m - blue
\033[22;35m - magenta
\033[22;36m - cyan
\033[22;37m - gray
\033[01;30m - dark gray
\033[01;31m - light red
\033[01;32m - light green
\033[01;33m - yellow
\033[01;34m - light blue
\033[01;35m - light magenta
\033[01;36m - light cyan
\033[01;37m - white
*/

#include <sstream>
#include <iostream>
#include <string>
using namespace std;

enum {BLACK=30, RED, GREEN, BROWN, BLUE, MAGENTA, CYAN, GREY, DGRAY, LRED, LGREEN, YELLOW, LBLUE, LMAGE, LCYAN, WHITE};

// --== Main Body ==--
template <class T>
void wc(T str, int color){
    stringstream ss;
    string str2;
    str2 = "\033[22;";  // escape sequence, bright
    ss << color;
    str2+= ss.str();
    str2+= "m";
    str2+= str;         // wanted color
    str2+= "\033[0m";   // reset the color
    cout << str2;
}
