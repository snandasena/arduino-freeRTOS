//
// Created by sajith on 3/7/22.
//

#ifndef UNTITLED10_BASE_H
#define UNTITLED10_BASE_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define RED 4
#define GREEN 6
#define YELLOW 9

typedef int TaskProfiler;

TaskProfiler RedLedProfiler;
TaskProfiler GreenLedProfiler;
TaskProfiler YellowLedProfiler;

const uint16_t *greeLed = (uint16_t *) GREEN;
const uint16_t *redLed = (uint16_t *) RED;
const uint16_t *yellowLed = (uint16_t *) YELLOW;

TaskHandle_t red_Handle;
TaskHandle_t green_Handle;
TaskHandle_t yellow_Handle;


#endif //UNTITLED10_BASE_H
