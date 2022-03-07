#include "timers/one_shot_n_auto_reload.h"

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
// write your initialization code here
    SetUp();
}


void loop()
{
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
// write your code here
}
