
#include <Fade.h>

int brightness1 = 255;
int brightness2 = 255;

Fade Fade1(33, 500, 0, brightness1,1);
Fade Fade2(10, 100, 2, 1200, 1);

void setup() 
{

  Serial.begin(9600);
  
}

void loop() 
{

    brightness1 = Fade1.runTimer();
    brightness2 = Fade2.runTimer();

    // Do sth with brightness
    if (Fade1.number == Fade1.mini)
    {
      Fade1.direct = 1;
    }
    if (Fade1.number == Fade1.maxi)
    {
      Fade1.direct = 2;
    }

    if (Fade2.number == Fade2.mini)
    {
      Fade2.direct = 1;
    }
    if (Fade2.number == Fade2.maxi)
    {
      Fade2.direct = 2;
    }
    
    
    Serial.print(Fade2.number);Serial.print(" ");Serial.println(Fade1.number);

}
