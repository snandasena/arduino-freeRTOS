#include "event_groups/event_group_demo2.h"

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
