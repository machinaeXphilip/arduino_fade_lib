#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Fade
{
  public:
    Fade(int steps, int interval, int minimum, int maximum, int direction = 1);
    int runTimer();
    int stepsize;
    int stepinterval;
    int number;
    int mini;
    int maxi;
    int direct; 
  private:
    boolean time2Update = false;
    uint32_t lastUpdate = 0;
};




#endif
