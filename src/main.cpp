#include <Dots.h>

Dots dots = Dots();

void setup()
{
    dots.shutdown(false);
    dots.setIntensity(7);
    dots.clearDisplay();

    Serial.begin(921600);
    Serial.println("Setup done!");
}

void loop()
{
    dots.beating1(200);
}
