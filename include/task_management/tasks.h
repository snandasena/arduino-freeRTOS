//
// Created by sajith on 3/2/22.
//

#ifndef UNTITLED10_TASKS_H
#define UNTITLED10_TASKS_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>


#define RED 8
#define GREEN 7
#define YELLOW 6

typedef int TaskProfiler;

TaskProfiler RedLedProfiler;
TaskProfiler YellowLedProfiler;
TaskProfiler GreenLedProfiler;

void redLedControllerTask(void *)
{
    pinMode(RED, OUTPUT);
    while (1)
    {
        RedLedProfiler++;
        Serial.print("RedLEDProfiler: ");
        Serial.println(RedLedProfiler);
        digitalWrite(RED, digitalRead(RED) ^ 1);
        delay(300);
    }


}

void greenLedControllerTask(void *)
{
    pinMode(GREEN, OUTPUT);
    while (1)
    {
        GreenLedProfiler++;
        Serial.print("GreenLEDProfiler: ");
        Serial.println(GreenLedProfiler);
        digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
        delay(300);
    }
}

void yellowLedControllerTask(void *)
{
    YellowLedProfiler++;
    pinMode(YELLOW, OUTPUT);
    while (1)
    {
        Serial.print("YellowLEDProfiler: ");
        Serial.println(YellowLedProfiler);
        digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
        delay(300);
    }
}

#endif //UNTITLED10_TASKS_H
