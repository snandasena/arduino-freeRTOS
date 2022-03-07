//
// Created by sajith on 3/7/22.
//

#ifndef UNTITLED10_BLOCKING_WITH_TASK_DELAY_H
#define UNTITLED10_BLOCKING_WITH_TASK_DELAY_H

#include "base.h"

const TickType_t _500ms = pdMS_TO_TICKS(500);

void redLedControllerTask(void *pvParams)
{
    pinMode(RED, OUTPUT);
    while (1)
    {
        digitalWrite(RED, HIGH);
        vTaskDelay(_500ms);
        digitalWrite(RED, LOW);
        vTaskDelay(_500ms);
    }
}

void greenLedControllerTask(void *pvParams)
{
    pinMode(GREEN, OUTPUT);
    while (1)
    {

    }
}

void yellowLedControllerTask(void *pvParams)
{
    pinMode(YELLOW, OUTPUT);
    while (1)
    {

    }
}


void SetUp()
{
    xTaskCreate(redLedControllerTask, "RED LED TASK", 100, NULL, 1, &red_Handle);
    xTaskCreate(greenLedControllerTask, "GREEN LED TASK", 100, NULL, 1, &green_Handle);
    xTaskCreate(yellowLedControllerTask, "YELLOW LED TASK", 100, NULL, 1, &yellow_Handle);

}

#endif //UNTITLED10_BLOCKING_WITH_TASK_DELAY_H
