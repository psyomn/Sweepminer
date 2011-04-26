#ifndef REN_CXX
#define REN_CXX

#include "Ren.hxx"
/** Default construct */
Ren::Ren(){
  srand( time ( NULL ) );
}

/** Default destruct */
Ren::~Ren(){}

/** Return a random number */
unsigned int 
Ren::getRandomNumber() {  
  unsigned int tmp = -1; // Set this to max
  return rand() % tmp;
}

/** Return a random number within positive range */
unsigned int 
Ren::getRandomNumber(unsigned int x) {
  return rand()%x;
}

#endif


