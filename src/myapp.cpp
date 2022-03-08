#include "timers/interation_with_multiple_timers.h"

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    SetUp();
}


void loop()
{
    digitalWrite(13, HIGH);
//    delay(200);
//    digitalWrite(13, LOW);
//    delay(200);
}
