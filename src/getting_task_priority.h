//
// Created by sajith on 3/3/22.
//

#ifndef UNTITLED10_GETTING_TASK_PRIORITY_H
#define UNTITLED10_GETTING_TASK_PRIORITY_H

#include "base.h"

int YellowLedPri;
int GreenLedPri;
int RedLedPri;

void redLedControllerTask(void *pvParams)
{
    while (1)
    {
//        ++RedLedProfiler;
//        Serial.print("RED Run Time: ");
//        Serial.println(RedLedProfiler);
//        delay(300);
    }
}

void greenLedControllerTask(void *pvParams)
{
    while (1)
    {
//        ++GreenLedProfiler;
//        Serial.print("Green Run Time: ");
//        Serial.println(GreenLedProfiler);
//        delay(300);
    }
}

void yellowLedControllerTask(void *pvParams)
{
    while (1)
    {
        ++YellowLedProfiler;
//        YellowLedPri = uxTaskPriorityGet(yellow_Handle);
        YellowLedPri = uxTaskPriorityGet(NULL); // only yellow
        GreenLedPri = uxTaskPriorityGet(green_Handle);
//        Serial.print("Yellow Task Priority: ");
        Serial.print("Green Task Priority: ");
//        Serial.println(YellowLedPri);
        Serial.println(GreenLedPri);
//        delay(300);
    }
}

void SetUp()
{
    xTaskCreate(redLedControllerTask, "RED LED TASK", 100, NULL, 1, &red_Handle);
    xTaskCreate(greenLedControllerTask, "GREEN LED TASK", 100, NULL, 1, &green_Handle);
    xTaskCreate(yellowLedControllerTask, "YELLOW LED TASK", 100, NULL, 3, &yellow_Handle);

}

#endif //UNTITLED10_GETTING_TASK_PRIORITY_H
