//
// Created by sajith on 3/2/22.
//

#ifndef UNTITLED10_CHANGE_TASK_PRIORITY_H
#define UNTITLED10_CHANGE_TASK_PRIORITY_H

#include "base.h"

TaskHandle_t red_Handle;
TaskHandle_t green_Handle;
TaskHandle_t yellow_Handle;


void redLedControllerTask(void *pvParams)
{
    pinMode(RED, OUTPUT);
    while (1)
    {
        digitalWrite(RED, digitalRead(RED) ^ 1);
        delay(50);
    }
}

void greenLedControllerTask(void *pvParams)
{
    pinMode(GREEN, OUTPUT);
    while (1)
    {
        digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
        delay(50);
    }
}

void yellowLedControllerTask(void *pvParams)
{
    pinMode(YELLOW, OUTPUT);
    while (1)
    {
        digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
        vTaskPrioritySet(NULL, 2);
        delay(300);
    }
}

void SetUp()
{
    xTaskCreate(redLedControllerTask, "RED LED TASK", 100, NULL, 1, &red_Handle);
    xTaskCreate(greenLedControllerTask, "GREEN LED TASK", 100, NULL, 1, &green_Handle);
    xTaskCreate(yellowLedControllerTask, "YELLOW LED TASK", 100, NULL, 1, &yellow_Handle);
}


#endif //UNTITLED10_CHANGE_TASK_PRIORITY_H
