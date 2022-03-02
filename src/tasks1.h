//
// Created by sajith on 3/2/22.
//

#ifndef UNTITLED10_TASKS1_H
#define UNTITLED10_TASKS1_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define RED 6
#define GREEN 7
#define YELLOW 8

typedef int TaskProfiler;

TaskProfiler RedLedProfiler;
TaskProfiler GreenLedProfiler;
TaskProfiler YellowLedProfiler;


const uint16_t *greeLed = (uint16_t *) GREEN;
const uint16_t *redLed = (uint16_t *) RED;
const uint16_t *yellowLed = (uint16_t *) YELLOW;

void ledControllerTask(void *pvParams)
{
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);

    while (1)
    {
        Serial.println("Connected");
        digitalWrite(pvParams, digitalRead(pvParams) ^ 1);
    }
}


#endif //UNTITLED10_TASKS1_H
