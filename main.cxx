#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Board.hxx"
#include "Ren.hxx"

int main(){
  Board b;
  Ren r;
  unsigned int px;
  unsigned int py;

  while(b.getState()){
    cout << " - Private view - " << endl;
    b.print();
    cout << " - Game view - " << endl;
    b.printGame();
	cout << "X coordinate: ";
	cin >> px;
	cout << "Y coordinate: ";
	cin >> py;
	b.pick(px, py);
  }

/*
  while(b.getState()) <- while game is ok.

*/

  return 0;
}
