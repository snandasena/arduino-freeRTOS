//
// Created by sajith on 3/6/22.
//

#ifndef UNTITLED10_SUSPENDING_A_TASK_H
#define UNTITLED10_SUSPENDING_A_TASK_H

#include "base.h"


void redLedControllerTask(void *pvParams)
{
    pinMode(RED, OUTPUT);
    while (1)
    {
        digitalWrite(RED, digitalRead(RED) ^ 1);
        vTaskDelay(100);
    }
}

void greenLedControllerTask(void *pvParams)
{
    pinMode(GREEN, OUTPUT);
    while (1)
    {
        digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
        if (suspend_monitor >= 7)
        {
//            vTaskSuspend(yellow_Handle);
            suspended = true;
            suspend_monitor = 0;
            vTaskSuspend(NULL);
        }
        vTaskDelay(100);
    }
}

void yellowLedControllerTask(void *pvParams)
{
    pinMode(YELLOW, OUTPUT);
    while (1)
    {
        ++suspend_monitor;
        digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
        vTaskDelay(100);

        if (suspended)
        {
            ++resume_monitor;
            if (resume_monitor >= 4)
            {
                vTaskResume(green_Handle);
                resume_monitor = 0;
                suspended = false;
            }
        }
    }
}

void SetUp()
{
    xTaskCreate(redLedControllerTask, "RED LED TASK", 100, NULL, 1, &red_Handle);
    xTaskCreate(greenLedControllerTask, "GREEN LED TASK", 100, NULL, 1, &green_Handle);
    xTaskCreate(yellowLedControllerTask, "YELLOW LED TASK", 100, NULL, 1, &yellow_Handle);

}

#endif //UNTITLED10_SUSPENDING_A_TASK_H
