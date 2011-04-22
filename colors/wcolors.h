/******************************************************************************
* Darkrunner: The Last Cyberpunk
*------------------------------------------------------------------------------
* Simon Symeonidis (C) 2009
*------------------------------------------------------------------------------
* This is a simple header file which will provide a 'clean' routine that will
* return a string with the required escape characters in order to color the
* terminal in windows.
* -----------------------------------------------------------------------------
* NOTES:
*  - To reset colors in windows mode, I simply change it back to seven (dark
*  gray). Maybe subject to change in the future.
******************************************************************************
TODO
  Must use generics...
  @file
******************************************************************************/

// Libs
#include <windows.h>
#include <string.h>
#include <iostream>
using namespace std;

// Glob Vars
enum {  BLACK, DBLUE, DGREEN, DCYAN, DRED, DMAGENTA,
DYELLOW, DWHITE, GRAY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE };

// Body ----

void wc(string str, int color)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    cout << str;
    SetConsoleTextAttribute(hConsole, 7);
}

void wc(int val, int color)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    cout << val;
    SetConsoleTextAttribute(hConsole, 7);
}

void wc(double val, int color)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    cout << val;
    SetConsoleTextAttribute(hConsole, 7);
}
