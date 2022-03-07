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


void redLedControllerTask(void *pvParams);

void greenLedControllerTask(void *pvParams);

void yellowLedControllerTask(void *pvParams);

#endif //UNTITLED10_BASE_H
