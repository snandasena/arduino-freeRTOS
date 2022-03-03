//
// Created by sajith on 3/2/22.
//

#ifndef UNTITLED10_TASK_PRIORITY_H
#define UNTITLED10_TASK_PRIORITY_H

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

void redLedControllerTask(void *pvParams)
{
    pinMode(RED, OUTPUT);
    while (1)
    {
        digitalWrite(RED, digitalRead(RED) ^ 1);
    }
}

void greenLedControllerTask(void *pvParams)
{
    pinMode(GREEN, OUTPUT);
    while (1)
    {
        digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
    }
}

void yellowLedControllerTask(void *pvParams)
{
    pinMode(YELLOW, OUTPUT);
    while (1)
    {

        digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
    }
}


#endif //UNTITLED10_TASK_PRIORITY_H
