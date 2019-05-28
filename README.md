# Fade Library for Arduino #

Library for "fading" integers up and down with parallel timers based on millis.
mainly aimed to dimm LEDs parallel in different steps and speeds. 
but might be useful for other stuff where we need incrementation or decrementation of ints

# Use #

first inanciate a Fade Object:
```cpp
#include <Fade.h>

Fade Fade1(33, 500, 0, 255,1);
```
the constructor needs 5 parameter:

1. **steps** : *int* - stepsize per step
2. **interval** : *int* - interval in ms
3. **minimum** : *int* - start fade at value 
4. **maximum** : *int* - stop fade at value
5. **direction** : *int* - 1 count up; 2 count down; 0 stop

then call every instance of Fade as needed via .runFade() method:

```cpp
#include <Fade.h>

int brightness1 = 255;

Fade Fade1(33, 500, 0, 255,1);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{

    brightness1 = Fade1.runTimer();

    if (Fade1.number == Fade1.mini)
    {
      Fade1.direct = 1;
    }
    if (Fade1.number == Fade1.maxi)
    {
      Fade1.direct = 2;
    }
    
    Serial.println(Fade1.number);

}
```

add as many instances of Fade as you like. They will run in parallel (see /Examples/FadeLibrary.ino for more)