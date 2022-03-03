//
// Created by sajith on 3/2/22.
//

#ifndef UNTITLED10_BASE_H
#define UNTITLED10_BASE_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define RED 7
#define GREEN 6
#define YELLOW 8

typedef int TaskProfiler;

TaskProfiler RedLedProfiler;
TaskProfiler GreenLedProfiler;
TaskProfiler YellowLedProfiler;

const uint16_t *greeLed = (uint16_t *) GREEN;
const uint16_t *redLed = (uint16_t *) RED;
const uint16_t *yellowLed = (uint16_t *) YELLOW;

#endif //UNTITLED10_BASE_H
