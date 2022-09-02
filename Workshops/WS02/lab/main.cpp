/* ------------------------------------------------------
Workshop 2 part 1
Module: N/A
Filename: main.cpp
Version 1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include "Car.h"
using namespace sdds;

int main(){
   Car C;
   VBPLE_Title();
   initialize(2); // set this later to 5
   while (read(C)) {
      record(C);
   }
   endOfDay();

}
/*
Copy and paste all the lines into the terminal instead of typing them.
Pasting in the terminal is usually done only by right clicking the mouse.

Toyota C-HR,VYEEDG,0001
Alfa Romeo Giulia,OVQXIQ,0004
Buick Encore GX,ZIQSUF,0007
Jeep Gladiator,YFQOSQ,1010
Chevrolet Impala,MWPBNW,1013
Volkswagen Atlas Cross Sport,ESIJDW,1116
Toyota Prius Prime,AECYJV,1319
Lexus RZ,QONGCT,1622
Tesla Model S,MCGSVD,2225
X,

*/
