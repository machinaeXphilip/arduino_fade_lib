/* 
 *  Fade.cpp - Library for "fading" integers up and down with parallel timers based on millis.
 *  mainly aimed to dimm LEDs parallel in different steps and speeds. 
 *  but might be useful for other stuff where we need incrementation or decrementation of ints
*/

//////////////////////////
/*  TO DO:
  - different fade effects (in particular: logarithmic fade for leds)
  - timer run out event (callback or status var?) with standart function
      (reverse direction)
      --> like the if causes in the example!
*/

#include "Arduino.h"
#include "Fade.h"

Fade::Fade(int steps, int interval, int minimum, int maximum, int direction)
{
  number = minimum;
  //number = 120; // testing only
  mini = minimum;
  maxi = maximum;
  stepsize = steps;
  stepinterval = interval;
  direct = direction;       // 1 UP 2 DOWN 0 STOPPED
  //direct = 2; // testing only
  //Serial.print("stepsize : ");Serial.print(stepsize);Serial.print(" stepinterval : ");Serial.print(stepinterval);
}

int Fade::runTimer()
{
  //check if time to update:

  if (millis() >= lastUpdate + stepinterval)
  {
    time2Update = true;
    lastUpdate = millis();
  }
  else
  {
    time2Update = false;
  }

  // if so, then do sth:
  if (time2Update)
  {
      if (direct == 1)
      {
          // increment number 
          number = number + stepsize;
          if (number > maxi)
            {
              number = maxi;
             }  
      }
      else if (direct == 2)
      {
          // decrement number 
            number = number - stepsize;
            if (number <= mini)
              {
                number = mini;
               }  
      }
      
      time2Update = false;
  }
  return number;
}

